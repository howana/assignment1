#include "ofApp.h"
bool redraw = false;
int currentPosX = 0;
int currentPosY = 0;
int CircleRadius = 100;
int thickness = 4;
ofSoundPlayer sound;
ofSoundPlayer click;
char SoundFXArray[5][30] = {"beep.mp3","beep2.mp3","beep3.mp3","beep4.mp3",};
//--------------------------------------------------------------
void ofApp::setup(){
	sound.setMultiPlay(true);
	ofNoFill();
	click.load("beep5.mp3");
	click.setLoop(true);
	click.play();
	click.setVolume(0.1f);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetLineWidth(thickness);
	ofSetFrameRate(12);
	ofBackground(ofColor::black);
	ofSetBackgroundAuto(false);
	currentPosX = ofGetScreenWidth() / 2;
	currentPosY = ofGetScreenHeight() / 2;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetSeconds()%5 == 0) {

		sound.load(SoundFXArray[int(ofRandom(0,4))]);
		sound.setSpeed(ofRandom(0.5, 1.2));
		sound.setPan(ofRandom(-1, 1));
		sound.play();
		currentPosX = ofRandom(0, ofGetWindowWidth());
		currentPosY = ofRandom(0, ofGetWindowHeight());
		redraw = false;
	}
	ofSetLineWidth(thickness);
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (redraw) {
		ofBackground(ofColor::black);
	}
	ofSetColor(ofColor::antiqueWhite);
	ofDrawCircle(ofRandom(currentPosX-CircleRadius, currentPosX+CircleRadius), 
		ofRandom(currentPosY-CircleRadius, currentPosY+CircleRadius), ofRandom(2,CircleRadius/8));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r') {
		redraw = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == 'w'){
		thickness += 1;
	}
	if ((key == 's') && (thickness >= 1)) {
		thickness -= 1; 
	}
	if (key == 'r') {
	redraw = false;
	}
	if (key == ' ') {
		currentPosX = ofRandom(0, ofGetWindowWidth());
		currentPosY = ofRandom(0, ofGetWindowHeight());
		redraw = false;
	}
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
