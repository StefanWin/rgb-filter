# rgb-filter

Apply simple RGB filters to images (jpg).  

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
```

### How to build
```
mkdir build
cd build
cmake ..
make
```
