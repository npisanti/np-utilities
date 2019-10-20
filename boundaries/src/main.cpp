
#include "ofMain.h"
#include "ofAppNoWindow.h"

class ofApp : public ofBaseApp{
public:

    ofFbo fbo;
    int width;
    int height;
    //---------------------------------------------------------------
    void setup(){

        fbo.allocate( 1920, 1080 );

        ofDisableAntiAliasing();
        fbo.begin();
        ofClear( 0, 0, 0, 0 );
        ofNoFill();
        ofDrawRectangle( 0, 0, width+1, height+1 );
        fbo.end();
    
    
        ofPixels pixels;
        fbo.readToPixels( pixels );
        ofSaveImage(pixels, "boundaries.jpg");

        ofExit();
    }

    //---------------------------------------------------------------
    void update() {

    }

    //---------------------------------------------------------------
    void exit(){

    }

};

//===================================================================
int main(int argc, char *argv[]){

    ofSetupOpenGL( 1920, 1080, OF_WINDOW);

    ofApp *app = new ofApp();
    
    app->width = 1280;
    app->height = 800;

    if(argc>1){		
        for( int i=1; i<argc; ++i ){
            switch( i ){
                case 1: app->width = ofToInt( argv[i] ); break;
                case 2: app->height = ofToInt( argv[i] );  break;
                default : break;
            }
        }   
    }
  
    ofRunApp( app );
}
