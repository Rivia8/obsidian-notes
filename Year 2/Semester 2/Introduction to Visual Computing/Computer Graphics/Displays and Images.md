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
