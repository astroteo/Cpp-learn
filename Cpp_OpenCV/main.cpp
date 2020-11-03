#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include<math.h>
//#include<highgui.h>

#include <boost/numeric/odeint.hpp>
#include <opencv2/photo.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <fstream>

using namespace::std;
using namespace::cv;


int main(){
  /* => opencv container for image data !
     => A = imread(argv[1], IMREAD_COLOR) */
  Mat m_img1;

  const char path[] = "MestessoSiteT.jpg";
  m_img1 = imread(path, IMREAD_COLOR);

  if(!m_img1.data){cout<<" wrong image load !"<<endl;}
  else{

    cout<< "Image correctly loaded " <<endl;

    // channels: int
    cout <<"channels: "<< m_img1.channels()<<endl;
    //columns: int
    cout <<"columns: "<< m_img1.cols<<endl;
    //rows: int
    cout <<"rows: "<< m_img1.rows<<endl;

  }


  bool display_original_img = true;
  if (display_original_img){

  namedWindow( "Display window", WINDOW_AUTOSIZE );    // Create a window for display.
  imshow( "Display window", m_img1);                   // Show our image inside it.

  waitKey(0);// Wait for a keystroke in the window
}

/* getting pixels value from the image => Mat object is nothing than a stupid object*/

//Vec3b -> integer value of pixels => tuple of 3 pixels!!

vector<Vec3b> all_px;

for (int i=0; i<m_img1.cols; i++){
  for(int j=0; j< m_img1.rows; j++){
                      //nested Vec3b object called .at()        //this is a point
    Vec3b bgr_px = m_img1.at<Vec3b>(i,j);// (Point(i,j)) as alternative
    all_px.push_back(bgr_px);




  }
}

//let's make an average of the pixels











  cout<< "hello, try installation for opencv"<<endl;
  return 0;









}

/*
compile this: g++ main.cpp -o app `pkg-config --cflags --libs opencv`
export PKG_CONFIG_PATH = /usr/local/lib/pkgconfig (if temporary setted )
*/
