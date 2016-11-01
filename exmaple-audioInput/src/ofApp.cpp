#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int sampleRate = 44100;
    int bufferSize = 256;
    
    // Setup frame size
    btrack.setup(bufferSize);
    
    // FIX: this is experimental inplementation.
    btrack.setConfidentThreshold(0.75);
    
    // Setup Audio Input
    ofSoundStreamSetup(0, 1, sampleRate, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // BPM
    ofSetColor(ofColor::black);
    float bpm = btrack.getEstimatedBPM();
    ofDrawBitmapString("Estimated BPM: " + ofToString(bpm, 1), 30, 50);
    ofDrawBitmapString("Confidence: " + ofToString(btrack.getConfidence(), 2), 30, 75); // confidence is an experimental feature at this moment
    

    // Beat
    ofDrawBitmapString("BEAT", 85, 195);
    if (btrack.hasBeat()) {    //FIXME: calling this method resets hasBeat flag in ofxBTrack object
        ofSetColor(ofColor::magenta);
    } else ofSetColor(ofColor::lightGray);
    ofDrawCircle(100, 150, 30);
}

//--------------------------------------------------------------
void ofApp::audioIn(float *input, int bufferSize, int nChannels){
    // feed audio frame into ofxBTrack object
    btrack.audioIn(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
