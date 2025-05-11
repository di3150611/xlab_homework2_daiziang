from PIL import Image

# 打开图片
image = Image.open('love.png').convert('1')  # 转换为黑白模式

# 获取图片大小
width, height = image.size

# 初始化字节数组
bitmap = bytearray((width * height + 7) // 8)

# 遍历图片像素
for y in range(height):
    for x in range(width):
        # 获取像素值
        pixel = image.getpixel((x, y))
        # 设置字节数组
        byte_index = (y * width + x) // 8
        bit_index = (y * width + x) % 8
        if pixel == 0:  # 黑色像素
            bitmap[byte_index] |= (1 << bit_index)

# 输出字节数组
print('const unsigned char PROGMEM bitmap[] = {')
for byte in bitmap:
    print(f'0x{byte:02X}, ', end='')
print('};')