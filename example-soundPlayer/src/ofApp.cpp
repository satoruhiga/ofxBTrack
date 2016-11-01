#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(speedSlider.setup("playback speed", 1.0, 0.75, 1.33));
    speedSlider.addListener(this, &ofApp::onSpeedliderChanged);
    
    // Load song file.
    player.load("dnb-loop-152.mp3"); // by AdRem1 - CC lisense - http://freesound.org/people/AdRem1/sounds/338951/
    player.play();
    player.setLoop(true);
    playbackBPM = originalBPM; // this song is known to be 120BPM.
}

void ofApp::onSpeedliderChanged(float &f){
    player.setSpeed(f);
    playbackBPM = originalBPM * f;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    ofSetColor(ofColor::black);
    ofDrawBitmapString("Original BPM: " + ofToString(originalBPM, 1), 20, 80);
    ofDrawBitmapString("Correct BPM: " + ofToString(playbackBPM, 1), 20, 100);
    
    // BPM
    ofSetColor(ofColor::black);
    float bpm = player.btrack.getEstimatedBPM();
    ofDrawBitmapString("Estimated BPM: " + ofToString(bpm, 1), 30, 150);
    
    // Beat
    ofDrawBitmapString("BEAT", 85, 210);
    if (player.btrack.hasBeat()) {    //FIXME: calling this method resets hasBeat flag in ofxBTrack object
        ofSetColor(ofColor::magenta);
    } else ofSetColor(ofColor::lightGray);
    ofDrawCircle(100, 250, 30);
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
