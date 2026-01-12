08-11-2025 20:15

Tags: [[C]]

# Musl

We have looked at the [[The C Standard Library|the C standard library]], often called `libc` which provides a core set of functions in C.
**Glibc (GNU C Library)** is the standard `libc` used by almost all major desktop and server Linux distributions, however, it is very large, complex and difficult to understand, so a simpler standard library **Musl** is what we will be looking at here.

Musl is a complete production-ready implementation built from scratch it is most famous for being the standard library used by **Alpine Linux**. Musl's main goal is to be simple, lightweight and complete, the size is much smaller than Glibc.

Here is an overall table for the reasons you can take one over the other:

| **Feature**      | **Glibc**              | **Musl**                     |
| ---------------- | ---------------------- | ---------------------------- |
| **Primary Goal** | Performance & Features | Simplicity & Size            |
| **Typical Use**  | Desktops, Servers      | Containers, Embedded Systems |
| **Size**         | Large                  | Very Small                   |
| **Complexity**   | Extremely High         | Relatively Simple            |

Another thing is that Musl is usually **statically linked** whereas Glibc is linked **dynamically**.