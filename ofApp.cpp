#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetWindowTitle("openFrameworks");
	ofSetFrameRate(30);

	ofBackground(0);
	ofSetColor(1, 97, 235);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
	int span = 20;
	int param = 7;

	for (int y = 0; y <= 720; y += span) {

		int x = ofMap(ofNoise(noise_seed.x, y * 0.003 + ofGetFrameNum() * 0.0075), 0, 1, span * param, 720 - span * param);
		x = (x / span) * span;

		ofDrawLine(x - span * param, y, x + span * param, y);
	}	

	for (int x = 0; x <= 720; x += span) {

		int y = ofMap(ofNoise(noise_seed.y, x * 0.003 + ofGetFrameNum() * 0.0075), 0, 1, span * param, 720 - span * param);
		y = (y / span) * span;

		ofDrawLine(x, y - span * param, x, y + span * param);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}