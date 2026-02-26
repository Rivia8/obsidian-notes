25-02-2026 16:54

Tags: [[Introduction to Visual Computing]]


Covers the following topics:

- Image histograms
- Grey-level mapping
- Thresholding
- Geometrical transformations

# Image Histograms

If we have the following image of a greyscale image:

![[Pasted image 20260225165920.png#invert]]

Its histogram will look like the following:

![[Pasted image 20260225165933.png#invert]]


![[Pasted image 20260225165955.png#invert]]

![[Pasted image 20260225170002.png#invert]]

The number of shades of grey we are able to represent increases the detail of the photo. If there are only a few shades of grey, it produces 'blotchiness'.


If we adjust the brightness we are essentially shifting the brightness left or right:


![[Pasted image 20260225170117.png#invert]]
![[Pasted image 20260225170102.png#invert]]


For contrast adjustment we have a similar procedure:

![[Pasted image 20260225170611.png#invert]]
![[Pasted image 20260225170630.png#invert]]

When changing contrast or brightness something important to consider is **clipping**. Clipping refers to when the value of the level of brightness (shade) is greater than the maximum possible value (255) and we cap the value to the highest instead of passing over.
This is because if we did $255 + 1 = 0$ or $255 + 2 = 1$, causing those pixels to go *darker* instead of brighter. 
Clipping essentially caps the brightness at the highest possible value:
![[Pasted image 20260225170933.png#invert]]

Clipping can be ensured via a simple `if-else` statement:

```Pseudocode
uint8 px = 250;
...
int32 p = px;
p += 50; // Increase brightness
if(p > 255) p = 255;
if(p < 0) p = 0;
px = p;
```

## Input-Output Mapping

![[Pasted image 20260226064847.png#invert|400]]

So the above image shows that when we adjust brightness, the difference is constant for all pixel values.

But with **contrast** its not the same:
![[Pasted image 20260226064957.png#invert|400]]
If we have a value that is 0 and multiply it by $k$, its still 0, and a larger value will have a larger affect than a smaller value, this means the darks stay dark and the lights get lighter.

![[Pasted image 20260226065106.png#invert]]
Mappings can be created in code with mathematical formula:

$$img[r][c] = img[r][c] \cdot 1.5$$

or with a lookup table:
![[Pasted image 20260226065240.png#invert]]

--- 

Here is an example with the solarise effect:

![[Pasted image 20260226065349.png]]
![[Pasted image 20260226065400.png]]

---

Here is another example of **Min-Max Linear Stretch:**
This is like a contrast adjustment.
![[Pasted image 20260226065457.png]]
![[Pasted image 20260226065505.png]]

---

Here is another example of **thresholding:**
![[Pasted image 20260226065535.png]]
![[Pasted image 20260226065542.png]]

When it comes to thresholding, how do we choose a value for the threshold, $T$?

