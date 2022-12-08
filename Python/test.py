from numpy import load

data = load('/Users/jeonminjeong/Downloads/CDY_2015.npz')
lst = data.files
for item in lst:
    print(item)
    print(data[item])
    break