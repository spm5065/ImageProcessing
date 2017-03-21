# ImageProcessing
Small programs for image processing 

**developMethodTesting** uses multiple different demosaicking algorithms upon the same image, and saves it multiple times to compare the differences.

**eqHisto** equalizes the histogram of a provided image

**exposureStack** takes multiple images and stacks them in a weighted method to allow for a lower noise image

**noiseReduction** takes an image or multiple images, and applies the nonLocalMeans denoising algorithm. Note: only completed multi exposure denoising.

**rawDevelop** develops raw images using the AMaZE demosaicking algorithm

**whiteBalance** applies a automatically computed white balance to an image

**blurDetection** calculates estimated blur using a modified laplacian. 
The lower the result, the higher the estimated blur is.
This method was described in a paper written by J. L. Pech-Pacheco, G. Cristobal, J. Chamorro-Martinez, and j. Fernandez-Valdivia. It was found at [http://optica.csic.es/papers/icpr2k.pdf](http://optica.csic.es/papers/icpr2k.pdf)
