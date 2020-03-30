﻿#include "pch.h"
#include <iostream>
#include "SpeechFeatures.h"
#include "DiscreteTransform.h"
using namespace cpp_speech_features;

int main()
{
	
	gc_start
		try {
		Vectorp data = create_verctorp_by_array(1024, 4, 4, 4, 4, 5, 5, 4, 4, 4, 5, 5, 8, 9, 10, 10, 11, 10, 8, 7, 6, 6, 5, 3, 3, 2, 2, 1, 2, 1, 0, -1, -3, -5, -7, -9, -10, -11, -13, -13, -12, -11, -11, -10, -8, -6, -3, -1, 2, 1, 1, -1, -2, -4, -5, -6, -7, -9, -10, -10, -10, -9, -6, -5, -4, -3, -2, -1, -1, -2, -2, -1, 2, 4, 4, 5, 3, 1, -1, -1, -2, -1, -1, -1, -2, -1, -2, -3, -4, -6, -9, -10, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, -2, -1, 0, -1, -2, -2, -2, -4, -3, -5, -5, -4, -5, -5, -6, -7, -8, -8, -8, -7, -6, -5, -3, -1, 2, 5, 10, 13, 17, 18, 18, 18, 18, 17, 17, 18, 17, 15, 13, 13, 12, 11, 12, 11, 13, 14, 14, 14, 14, 13, 14, 15, 17, 18, 17, 18, 18, 18, 17, 16, 14, 13, 11, 10, 10, 8, 7, 4, 1, -2, -4, -6, -5, -4, -5, -3, -4, -3, -2, -1, 1, 2, 2, 3, 3, 2, 1, -2, -5, -10, -15, -20, -23, -26, -28, -29, -29, -28, -27, -23, -21, -19, -16, -14, -13, -13, -11, -12, -13, -13, -13, -12, -12, -10, -9, -8, -7, -8, -9, -7, -8, -7, -6, -5, -4, -3, -1, -1, -1, -3, -4, -4, -5, -3, -4, -3, -4, -8, -11, -13, -14, -16, -17, -17, -18, -18, -16, -15, -12, -10, -6, -4, 0, 3, 7, 9, 9, 10, 11, 11, 11, 10, 11, 9, 8, 6, 5, 3, 4, 5, 7, 9, 10, 11, 9, 7, 4, 2, 1, 0, 2, 5, 8, 10, 10, 10, 8, 9, 9, 8, 6, 6, 3, 1, 0, -3, -5, -8, -9, -10, -8, -6, -2, 0, 3, 4, 5, 8, 10, 13, 15, 16, 16, 14, 13, 12, 11, 8, 7, 6, 2, 0, -1, -3, -3, -4, -4, -2, 0, 3, 5, 7, 6, 7, 6, 8, 9, 11, 14, 15, 18, 20, 22, 25, 26, 25, 25, 26, 27, 28, 27, 26, 24, 20, 18, 16, 15, 14, 14, 13, 14, 15, 16, 14, 11, 6, 0, -4, -6, -9, -10, -11, -13, -13, -12, -10, -7, -4, -2, 0, 1, 2, 1, -2, -6, -11, -16, -22, -26, -31, -33, -39, -42, -44, -42, -39, -32, -26, -19, -13, -8, -5, -3, -2, -3, -5, -7, -8, -11, -13, -15, -17, -18, -21, -24, -27, -28, -30, -29, -28, -26, -23, -21, -17, -13, -8, -3, 1, 3, 5, 6, 5, 6, 3, 0, -5, -11, -17, -21, -26, -30, -31, -31, -28, -25, -23, -19, -15, -9, 0, 10, 19, 27, 36, 41, 47, 52, 57, 59, 58, 55, 50, 42, 37, 29, 20, 10, -1, -11, -18, -21, -22, -21, -19, -13, -5, 5, 16, 27, 37, 47, 54, 58, 58, 55, 49, 42, 32, 23, 12, 0, -12, -23, -30, -37, -40, -45, -46, -45, -42, -36, -28, -20, -10, -1, 9, 19, 28, 36, 41, 42, 41, 36, 32, 25, 16, 6, -6, -19, -31, -43, -54, -62, -68, -72, -72, -68, -62, -54, -43, -31, -18, -4, 10, 22, 30, 36, 38, 39, 36, 30, 22, 12, 1, -9, -18, -25, -31, -37, -40, -43, -43, -39, -35, -32, -29, -27, -25, -22, -22, -23, -26, -33, -41, -50, -60, -73, -86, -98, -110, -119, -127, -131, -133, -133, -130, -125, -119, -111, -102, -90, -77, -64, -51, -38, -24, -11, 2, 14, 25, 33, 38, 43, 46, 48, 50, 48, 45, 41, 41, 40, 42, 46, 53, 62, 73, 87, 101, 115, 129, 142, 156, 166, 174, 178, 179, 177, 171, 165, 156, 149, 144, 140, 137, 135, 134, 133, 135, 138, 139, 142, 142, 143, 142, 141, 137, 131, 123, 114, 104, 95, 87, 80, 74, 69, 65, 59, 53, 48, 42, 35, 29, 22, 15, 9, 4, 1, -3, -5, -6, -7, -8, -7, -7, -7, -9, -10, -11, -14, -17, -23, -27, -31, -35, -39, -40, -40, -37, -33, -28, -20, -11, -1, 8, 16, 22, 28, 32, 36, 38, 39, 39, 35, 32, 29, 26, 24, 20, 15, 11, 6, 1, -4, -11, -18, -27, -38, -47, -56, -67, -77, -88, -97, -107, -117, -123, -130, -135, -138, -140, -141, -141, -142, -143, -148, -159, -177, -204, -238, -280, -327, -378, -430, -483, -530, -573, -607, -629, -639, -632, -612, -578, -532, -476, -414, -348, -280, -216, -160, -110, -70, -43, -26, -23, -30, -42, -60, -76, -85, -89, -83, -68, -48, -17, 17, 54, 94, 132, 167, 202, 235, 266, 299, 332, 365, 398, 430, 461, 489, 513, 531, 541, 542, 532, 510, 478, 435, 386, 333, 279, 227, 182, 150, 130, 127, 139, 165, 197, 232, 267, 296, 314, 324, 322, 305, 278, 241, 196, 147, 95, 43, -7, -52, -91, -123, -148, -166, -174, -177, -175, -169, -161, -152, -146, -142, -139, -138, -136, -134, -129, -121, -109, -93, -77, -60, -46, -36, -30, -30, -35, -45, -62, -81, -101, -119, -134, -141, -144, -139, -125, -103, -72, -32, 12, 59, 107, 150, 191, 221, 243, 252, 249, 234, 212, 184, 155, 126, 99, 75, 56, 44, 38, 38, 46, 59, 75, 94, 115, 134, 148, 156, 157, 154, 147, 137, 125, 112, 99, 88, 77, 67, 60, 52, 44, 34, 24, 10, -1, -14, -25, -31, -35, -34, -28, -17, -3, 13, 28, 42, 55, 65, 73, 77, 76, 68, 54, 32, 4, -29, -62, -95, -121, -140, -151, -149, -137, -115, -86, -54, -21, 9, 36, 57, 70, 77, 75, 68, 53, 37, 15, -8, -30, -54, -77, -95, -111, -121, -128, -135, -143, -159, -186, -228, -287, -363, -451, -549, -644, -733, -807, -862, -898, -913, -906, -880, -837, -781, -716, -645, -570, -494, -422, -352, -288, -233, -192, -165, -157, -164, -187, -217, -245, -268, -275, -266, -238, -192, -132, -63, 9, 77, 136, 187, 227, 265, 304, 347, 394, 447, 504, 563, 617, 663, 695, 712, 712, 700, 676, 643, 605, 559, 508, 451, 388, 322, 257, 198, 155, 133, 138, 170, 227, 300);
		Matrixp mfcc_feat0 = SpeechFeatures::mfcc(data);
		Matrixp mfcc_feat1 = SpeechFeatures::delta(mfcc_feat0, 1);
		Matrixp mfcc_feat2 = SpeechFeatures::delta(mfcc_feat0, 2);
		mfcc_feat2->print();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	gc_release	
}


