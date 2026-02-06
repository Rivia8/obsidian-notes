06-02-2026 13:13

Tags: [[System Architecture]]

# Addressing

## Address Spaces

The [[3-Box Model of the Computer]] is explored within the [[System Architecture]] module. The model is adequate but is not always the whole story.

Memory lives in an address space and when you have $n$ bits you have $2^n$ address locations. The size of the address space is set by the architecture.
Until recently it was not practical to fill a 32-bit address space with *actual* memory ($2^{32} \approx 4\text{Gi} ~ \text{locations}$) a 64-bit address can hold **ALOT** more.

A byte is almost always 8-bits.
A word depends on the architecture, most the time 32-bits.

![[Pasted image 20260206133413.png#invert]]
When you are accessing data from memory you usually retrieve a 'word' of bits. If you for some reason need to access more than a word or you need to get data that flows on to the following 'shelf' (memory is sort of arranged in shelves, not actually its contiguous but the bus is wired in a 'grid-like' way) it might need to **2 clock cycles** or **truncating** the address. To fix this we do something called '**alignment**'.

## Alignment

Alignment is wher






