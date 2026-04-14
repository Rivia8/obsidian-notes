13-04-2026 18:24

Tags: [[Introduction to Visual Computing]]

When it comes to how humans view an object, a light source, lets say a lightbulb will emit light and the object will reflect the light to the person's eye.

![[Pasted image 20260413182716.png|300]]
A human has two types of photo receptors, these are what detect light and its colours within the eyes. 
One type are **rods** and the other **cones**.
**Rods** are highly sensitive to light so allow for low-light vision but do not detect colour whilst **cones** are *less* sensitive but detect colour. 

![[Pasted image 20260413183204.png#invert]]

when it comes to light and how sensitive we are to them, our *cones* are more sensitive to **green** light, as you can see in the graph.

![[Pasted image 20260413183541.png|200]]


In our eye we have something called the **fovea**, this is a small area within the retina where cones are the most concentrated as to opposed to the **perifovea** which deals with peripheral vision.

![[Pasted image 20260413183701.png#invert]]

The **foveal** handles the object that we are focusing on, so our direct vision rather than peripheral vision.

![[Pasted image 20260413184049.png#invert]]

Cameras have something called a Bayer filter that is placed on-top of the sensor. it matches the human eye by having twice as many green filters than red and blue. A cameras sensor only detects the **intensity** of light, the filter sits on top only allowing certain colours to pass and the camera then re-adds the missing colours

When it comes to creating colours, it is RGB additive which means adding different combinations of Red, Green and Blue together (different to the primary colours).

**Rasterization** is the computer graphics process of converting vector-based images (mathematical shapes, lines, and curves) into a raster format (a grid of pixels, dots, or lines) for display on screens or printers.
![[Pasted image 20260413185033.png]]

Each **Pixel** (Picture element) contains RGB data for all 3 colour channels in $[0,1]$.  We cannot display the infinite range of $[0,1]$ so we quantise the values and we use 8-bits to contain the colour information of each pixel.
To quantise the float, you multiple the $[0,1]$ value by the maximum integer value (here it would be 255) and rounds it to the nearest whole number:
$$C_\text{s-bit} = round(C_\text{float} \times 255$$This means that multiple floating-point numbers will map to the same hardware pixel value.

$$\textbf{Resolution} = \textbf{height} \times \textbf{width} $$
A pixel isn't actually a square
![[Pasted image 20260414130942.png]]

Its something called a **Dimensionless Point Sample**. 
In the continuous math of rendering, a pixel has no area, no width and no boundaries, it is simply a **discrete**, **infinitely small** coordinate in 2D space.

They only look square since we take that sample and we paint it with **box filters**, operations with squares is just easier to compute.

Distance between pixels are usually constant, it is known as **PPI** (Pixels Per Inch)
![[Pasted image 20260414131233.png]]

Higher PPI = Higher Quality

Pictures that are displayed with pixels are called **Raster Images**.
Raster images need each pixel to store RGB data stored for each pixel.

Pixels in this forma are read in **scanline order** and stored in a **1D array** in memory.

![[Pasted image 20260414131623.png]]

*These come came from old cathode-ray televisions where they used scan lines*

Another way of reading the images is ***Swizzling*** or **Z-Order Curves**.

![[Pasted image 20260414132809.png]]

This better for *clustered items* since instead of just rendering images in a scan-line you render for the tendency of objects to be clustered together, this is known as **Spatial Coherency**.

![[Pasted image 20260414133246.png]]


If you had a 1080p display: $1920 \times 1080~ \textbf{pixels}~ = 2,073,600$ and since each pixel has 3 colour channels it has to store $6,220,800$ individual numbers just to hold a single frame.

You can order the data into ways,
**Interleaved** or **Non-Interleaved**

For **Interleaved** all the data for each pixel is kept together, the Red, Green and Blue values for the first pixel are followed by the second etc. This allows for the CPU/GPU to be able to fetch an entire pixel in one read which maximises cache efficiency.

For **non-interleaved** (or **Planar**) you store every single Red value for the entire image first, then Green, and then Blue. This is preferred for image processing as you can isolate and adjust individual colour channels.

When it comes to lighting, the difference between the brightest and darkest parts of the scene is known as **Dynamic Range**.

**Low DR (LDR)** - White is the maximum
	1, 8, 16, 24 (rare) bits Colour channels

**High DR (HDR)** -  We can go beyond white
	16, 32 bits Colour channels

This information is useful for making images look realistic

When it comes to *how* images are stored, there are different formats.

1. PPM
![[Pasted image 20260414133724.png]]
This format has very large file sizes

Bitmap files are similar but a bit more space efficient.

2. PNG

![[Pasted image 20260414133835.png]]

