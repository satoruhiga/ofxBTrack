//
//  ofxFmodSoundPlayer.cpp
//  TurntableSimulator
//
//  Created by Nao Tokui on 2015/09/02.
//
//

#include "ofxFmodSoundPlayer.h"

bool bXFmodInitialized_ = false;

void ERRCHECK(FMOD_RESULT result)
{
    if (result != FMOD_OK){
        fprintf(stderr, "FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}

FMOD_RESULT F_CALLBACK analyzerCallback(FMOD_DSP_STATE *dsp_state,
                                        float *inbuffer, float *outbuffer,
                                        unsigned int length, int inchannels,
                                        int outchannels)

{
    // handle 512 sample each time /  called 23 time per sec
    
    // pass the data along
    memcpy(outbuffer, inbuffer, sizeof(float)* length * outchannels);
    
    void *userdata = NULL;
    FMOD_DSP_GetUserData(dsp_state->instance, &userdata);
    ofxFmodSoundPlayer *player = (ofxFmodSoundPlayer *)userdata;

    // BPM analysis
    ofxBTrack *btrack = &(player->btrack);
    if (btrack) btrack->audioIn(inbuffer, length, inchannels);
    
    return FMOD_OK;
}

ofxFmodSoundPlayer::ofxFmodSoundPlayer(){

}

void ofxFmodSoundPlayer::play(){
    ofFmodSoundPlayer::play();

    // Setup
    FMOD_SYSTEM  *system;
    FMOD_RESULT result  = FMOD_Sound_GetSystemObject(sound, &system);
    ERRCHECK(result);

    unsigned int bufferLength;
    result  = FMOD_System_GetDSPBufferSize(system, &bufferLength, NULL);
    ERRCHECK(result);
    
    // Adjust buffer size
    btrack.setup(bufferLength);
    
    // Analyzer
    FMOD_DSP_DESCRIPTION dsp_description;
    memset(&dsp_description, 0, sizeof(FMOD_DSP_DESCRIPTION));
    strcpy(dsp_description.name, "Audio Analyzer DSP");
    dsp_description.channels     = 0;
    dsp_description.read         = analyzerCallback;
    dsp_description.userdata     = this;
    result = FMOD_System_CreateDSP(system, &dsp_description, &analyzer);
    ERRCHECK(result);
    
    // Create DSP
    result = FMOD_Channel_AddDSP(channel, analyzer, 0);
    ERRCHECK(result);
}


