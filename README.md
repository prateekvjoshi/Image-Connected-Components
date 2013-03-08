# ConnectedComponents

This code is based on OpenCV and it finds connected components in a given image. It basically finds different objects in the image and colors each connected region with a different color. Sample input image along with the corresponding output is included in this project. There is a file called "CMakeLists.txt". This file will used to build the project (if you have built OpenCV using cmake). If not, just use the .cpp file in your project and build it. To build using command line, follow the steps below to get it up and running:

	$ cmake .
	$ make
	$ ./main inputImage.jpg

The output will be displayed on a window and also written onto the "outputImage.jpg" in the same folder. 