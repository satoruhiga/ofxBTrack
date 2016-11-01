//
//  ofxFmodSoundPlayer.h
//
//
//  Created by Nao Tokui on 2015/09/02.
//
//

#ifndef ofxFmodSoundPlayer_h
#define ofxFmodSoundPlayer_h

#include "ofFmodSoundPlayer.h"
#include <math.h>

#include "ofxBTrack.h"

class ofxFmodSoundPlayer : public ofFmodSoundPlayer
{
    public:
    ofxFmodSoundPlayer();
    
    void play();
    
    ofxBTrack btrack;
    
    private:
    FMOD_DSP       *analyzer;
};

#endif