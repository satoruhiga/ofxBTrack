//
//  ofxBTrack.cpp
//  BTrackTest
//
//  Created by Nao Tokui on 11/1/16.
//
//

#include "ofxBTrack.h"

void ofxBTrack::setup(int framesize){
    setup(framesize, framesize/2);
}

void ofxBTrack::setup(int framesize, int hopsize){
    b.updateHopAndFrameSize(hopsize, framesize); // caution: the order of hopsize and framesize
    frameSize = framesize;
}

float ofxBTrack::getEstimatedBPM(){
    if (confidence > confidenceThreshold){
        return bpm_;
    } else {
        return 0.0;
    }
}

 //FIXME: calling hasBeat() resets hasBeat flag
bool ofxBTrack::hasBeat(){
    bool tmpHasBeat = hasBeat_;
    hasBeat_ = false;
    
    if (confidence > confidenceThreshold){
        return tmpHasBeat;
    } else {
        return false;
    }
 }

float ofxBTrack::getConfidence(){
    return confidence;
}

void  ofxBTrack::setConfidentThreshold(float thresh){
    confidenceThreshold = thresh;
}

void ofxBTrack::audioIn(float *input, int bufferSize, int nChannels)
{
    b.processAudioFrame((double *)input);
    
    if (b.beatDueInCurrentFrame()){
        hasBeat_ = true;
        
        //FIXME: need to figure out how to calculate properly
        confidence = b.getLatestCumulativeScoreValue() / (float) frameSize * 10000.0;
    }
    bpm_ = b.getCurrentTempoEstimate();    
}
