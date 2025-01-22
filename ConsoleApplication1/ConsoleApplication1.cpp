#include <opencv2/opencv.hpp>         // OpenCV'nin temel özellikleri için
#include <opencv2/highgui.hpp>       // Görüntü ve video gösterimi için
#include <opencv2/imgproc.hpp>       // Görüntü işleme işlemleri için
#include <opencv2/core.hpp>          // Temel veri yapıları ve işlevler için
#include <opencv2/objdetect.hpp>     // Nesne algılama, yüz tanıma için (Haar Cascade ve benzeri)
using namespace std;
using namespace cv;
/*void mousetiklanmasi(int olay, int x, int y, int flag, void* veri) {
    if (olay == EVENT_LBUTTONDOWN) {
        cout << "sol tusa tiklandi:" << endl;

    }
    else if (olay == EVENT_LBUTTONUP) {
        cout << "sol tustan el cekildi:" << endl;
    }
    else if (olay == EVENT_MOUSEMOVE) {
        cout << "fare kacanzii:" << endl;
    }
    else if (olay == EVENT_MOUSEWHEEL) {
        cout << "mouse tekerlegi hareket etti:" << endl;
        if (flag > 0)
            cout << "arti yönde" << "degeri:" << flag << endl;
        else if (flag < 0)
            cout << "eksi yönde" << "degeri:" << flag << endl;
    }

}
void mouseevent() {
    string pencere1 = "mouse olaylari";
    Mat resim = Mat::zeros(Size(640, 480), CV_8UC3);
    imshow(pencere1, resim);
    setMouseCallback(pencere1, mousetiklanmasi);
    waitKey();
}*/
bool cizim = false;
void mouseolaylari(int olay, int x, int y, int bayrak, void* kullanıcıverisi) {
    Mat *resim = (Mat*)kullanıcıverisi;
     
    if (olay == EVENT_LBUTTONDOWN) {
        cizim = true;
    }
    else if (olay == EVENT_LBUTTONUP) {
        cizim = false;
    }
    if (cizim) {
        resim->at<Vec3b>(Point(x, y))[0] = 255;
        resim->at<Vec3b>(Point(x, y))[1] = 0;
        resim->at<Vec3b>(Point(x, y))[2] = 0;
        imshow("pencerem", *resim);
    }
    
}
void mouseilepaint() {
    Mat resim = Mat::zeros(Size(800, 600), CV_8UC3);
    string winName = "pencerem";
    imshow(winName, resim);
    setMouseCallback(winName, mouseolaylari, &resim);
    waitKey();

}
    
int main()
{
    string dosya_yolu = ("C:/deneme/test1.jpg");
    //mouseevent();
    mouseilepaint();
}

