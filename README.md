# rgb-filter

Apply simple RGB filters to images (jpg).  
Build with C++ 17, CMake and [stb](https://github.com/nothings/stb).

### Usage:
```rgb-filter <input> <filter <output>```

```
<input> -> path to a jpg file
<filter> -> one of the supported filters
<output> -> path to the output file
```

### Supported Filters
```
grayscale  
invert  
remove-red  
remove-green  
remove-blue  
sort  
reverse-sort  
bgr  
clamp-50  
clamp-100  
r  
g  
b  
rg  
rb  
gb  
```

### How to build
```
mkdir build
cd build
cmake ..
make
```

