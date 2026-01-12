08-11-2025 17:46

Tags: [[C]]

# High Performance Computing

C is close to hardware and because of this it is fast and so is used extensively in high performance computing. The programming language also gives us lots of control of memory, this is unlike many other programming languages like Python (a high level language which is interpreted rather than compiled, this gives it large overhead).

![[layers.svg#invet|500]]

Another form of overhead is garbage collection, Python and Java have automatic garbage collection, however, C does not. This is a double-edged blade however, as it can cause memory leaks which can lead to massive instability if the programmer is not careful.

## Making C Code Memory and Cache Friendly

In a 64 bit system, a word is 64 bits, this means that for every fetch process in the fetch-execute cycle, 64 bits can be loaded and decoded. If we had a [[Custom Data Structures|custom data type]] that was more than 64 bits (for no important reason or just in a general case), that would require **two** fetches. This is slow and inefficient - it is best for the data type to be equal or less than a 'word size' of the system.
This also applies to cache, a cache line can hold 64 **bytes** of data, and if you were to have a `struct` that was **larger** than that, it would result in multiple fetch operations, this is **slow** and **inefficient.** This is due to the fact that the rest of the data is in RAM which is much slower than cache - you want to be successfully fetching from cache, a cache hit and **not miss.** 

Let's look at the following example:

```C
typedef struct {
    char c[60];
    int i;
    double d;
} my_struct;

#define N 100000000
my_struct array[N];

int main(int argc, char **argv) {
  struct timeval start, stop, res;
  my_struct s;

  gettimeofday(&start, NULL);

  /* Randomly access N elements */
  for(int i=0; i<N; i++)
      memcpy(&s, &array[rand()%N], sizeof(my_struct));

  gettimeofday(&stop, NULL);
  timersub(&stop, &start, &res);
  printf("%ld.%06ld\n", res.tv_sec, res.tv_usec);

  return 0;
}
```

We can see that we have a [[Programming Languages and Frameworks/Java/1. Fundamentals & Core Concepts/Strings|String]] that is 60 bytes long and then an `int` and then a `double`, in total this would be: 60 + 4 + 8 = 72 bytes. This is larger than 64 and would cause a cache miss every time this would be called.
This is how cache lines would look like in memory, with reference to our `struct` above:

![[alignment.svg#invert|800]]

There are various ways to fix this issue, we can just reduce the size by removing unnecessary data, if we can we can use alignment or packing.  