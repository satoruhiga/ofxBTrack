//
//  ofxBTrack.h
//  BTrackTest
//
//  Created by Nao Tokui on 11/1/16.
//
//

#ifndef ofxBTrack_h
#define ofxBTrack_h

#include <stdio.h>
#include "BTrack.h"

#include <deque>
#include <vector>

class ofxBTrack {
    
    public:
        // Frame size affects  
        void setup(int framesize);
        void setup(int framesize, int hopsize);

        // Whether or not beat should appear in the current frame
        bool hasBeat();
    
        // Get current estimated BPM
        float getEstimatedBPM();
    
        // Experimental Features:
        // How confident in the estimation
        float getConfidence();
    
        // Output beat and bpm only if confident value > confident threshold
        void setConfidentThreshold(float thresh);
    
        // Feed audio frames
        void audioIn(float *input, int bufferSize, int nChannels);

    private:
		
		std::deque<double> buffer;
		std::vector<double> processBuffer;
		
        BTrack b;
        int frameSize;
        float confidence;
        float confidenceThreshold = 0.0;
    
        float  bpm_;
        bool   hasBeat_;
};


#endif /* ofxBTrack_h */
