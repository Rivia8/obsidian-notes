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

If you have a 32-bit (4-byte) system, your memory isn't one column of bytes. It is physically for parallel columns.

**Row 0 (address 0 to 3):** 0, 4, 8, 12
**Row 1 (addresses 4 to 7):** 1, 5, 9, 13
**Row 2 (addresses 8 to 11):** 2, 6 ,10, 14

When you want to read address 4. The CPU will activate 'Row 1' and reads 




