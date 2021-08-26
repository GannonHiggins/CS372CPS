#include "Shape.hpp"
#include <fstream> //test file 

int main() {
   auto eye = makeLayeredShape({makeCircle(80), makeVerticalShape({makeSpacer(90, 90), makeCircle(30)})});
   auto eyes = makeHorizontalShape({eye, makeSpacer(20, 20), makeRotatedShape(eye, Rot::R90)});
   auto nose = makeLayeredShape(
         {makeTriangle(100),
          makeVerticalShape({makeHorizontalShape({makePolygon(5, 10), makeSpacer(20, 20), makePolygon(5, 10)}),
                             makeSpacer(40, 40)})});
   auto face = makeVerticalShape({makeRectangle(200, 10), makeSpacer(50, 50), nose, makeSpacer(-20, -20), eyes});
   std::ofstream ofs("face.ps");
   ofs << "306 306 moveto\n" << face->getPostScript() << "showpage\n";
   return 0;
}
