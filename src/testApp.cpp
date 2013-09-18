#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofBackground(40, 100, 40);
    
	// open an outgoing connection to HOST:PORT
	sender.setup(HOST, PORT);
    
	leap.open();
    
    leap.setupGestures();   // we enable our gesture detection here
}

//--------------------------------------------------------------
void testApp::update(){
    
    leap.updateGestures();  // check for gesture updates
    
	//IMPORTANT! - tell ofxLeapMotion that the frame is no longer new.
	leap.markFrameAsOld();
    
}

//--------------------------------------------------------------
void testApp::draw(){
	// display instructions
	string buf;
	buf = "sending osc messages to " + string(HOST) + ":" + ofToString(PORT);
	ofDrawBitmapString(buf, 10, 20);
    
    /* Leap iGesture Key
     --------------------------------
     1 = Screen Tap
     2 = Key Tap
     3 = Swipe Right
     4 = Swipe Left
     5 = Swipe Down
     6 = Swipe Up
     7 = Swipe Forward
     8 = Swipe Backward (towards yourself)
     9 = Circle Left (counter-clockwise)
     10 = Circle Right (clockwise)
     --------------------------------
     */
    
    string msg;
    
    ofxOscMessage m;
    
    switch (leap.iGestures) {
        case 1:
            msg = "Screen Tap";
            m.setAddress("/leap/gesture/screentap");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 2:
            msg = "Key Tap";
            m.setAddress("/leap/gesture/keytap");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 3:
            msg = "Swipe Right";
            m.setAddress("/leap/gesture/swiperight");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 4:
            msg = "Swipe Left";
            m.setAddress("/leap/gesture/swipeleft");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 5:
            msg = "Swipe Down";
            m.setAddress("/leap/gesture/swipedown");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 6:
            msg = "Swipe Up";
            m.setAddress("/leap/gesture/swipeup");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 7:
            msg = "Swipe Forward";
            m.setAddress("/leap/gesture/swipeforward");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 8:
            msg = "Swipe Backwards";
            m.setAddress("/leap/gesture/swipebackwards");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 9:
            msg = "Circle Left";
            m.setAddress("/leap/gesture/circleleft");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        case 10:
            msg = "Circle Right";
            m.setAddress("/leap/gesture/cirlceright");
            // m.addIntArg(1);
            sender.sendMessage(m);
            break;
            
        default:
            msg = "Waiting for hand movement...";
            break;
    }
    
    ofDrawBitmapString(msg, 10, 40);  // let's draw our message to the screen
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void testApp::exit(){
    leap.close();  // let's close down Leap and kill the controller
}


