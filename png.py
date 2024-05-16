from PIL import Image
import cairo

# PNG画像を開く
png_image = Image.open('result_pr1_ndup.png')

# RGBモードに変換
png_image_rgb = png_image.convert('RGB')

# 画像のサイズを取得
width, height = png_image_rgb.size

# CairoのImageSurfaceを作成
surface = cairo.ImageSurface(cairo.FORMAT_ARGB32, width, height)
context = cairo.Context(surface)

# PIL画像のデータをCairoのImageSurfaceにコピー
for y in range(height):
    for x in range(width):
        r, g, b = png_image_rgb.getpixel((x, y))
        context.set_source_rgb(r / 255, g / 255, b / 255)
        context.rectangle(x, y, 1, 1)
        context.fill()

# EPSファイルとして保存
surface.write_to_png('output.eps')