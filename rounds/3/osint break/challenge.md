# osint break

- Published: 03/18/2024 (#4/6 in round)
- Category: OSINT/Steg.
- Points: 30
- Author: Vipin

maybe its time to go back to the basics of osint...

## Attachments

- [osintbreak.jpeg.zip](osintbreak.jpeg.zip)

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

look into exiftool

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

To solve this challenge, we will be utilizing EXIFtool to get the job done. 

```bash:Terminal
❯ exiftool osintbreak.jpeg
ExifTool Version Number         : 12.76
File Name                       : osintbreak.jpeg
Directory                       : .
File Size                       : 50 kB
File Modification Date/Time     : 2024:03:18 11:34:12-04:00
File Access Date/Time           : 2024:04:02 10:38:29-04:00
File Inode Change Date/Time     : 2024:04:02 10:38:18-04:00
File Permissions                : -rw-r--r--
File Type                       : JPEG
File Type Extension             : jpg
MIME Type                       : image/jpeg
JFIF Version                    : 1.01
Image Description               : Nkrumah Memorial Park - First president of independent Ghana, West Africa
X Resolution                    : 300
Y Resolution                    : 300
Resolution Unit                 : inches
Software                        : 0x630x730x640x7b0x310x5f0x440x300x4e0x370x5f0x370x720x550x350x370x5f0x340x5f0x350x300x550x310x5f0x310x5f0x440x300x4e0x370x5f0x370x720x550x350x370x5f0x4e0x300x380x300x440x590x7d
Copyright                       : Jacek_Sopotnicki
Exif Version                    : 0210
# Half of the output is cut off for space
```

The software seems to have some sort of hexadecimal text.

```bash:Terminal
❯ echo "0x630x730x640x7b0x310x5f0x440x300x4e0x370x5f0x370x720x550x350x370x5f0x340x5f0x350x300x550x310x5f0x310x5f0x440x300x4e0x370x5f0x370x720x550x350x370x5f0x4e0x300x380x300x440x590x7d" | xxd -r -p
csd{1_D0N7_7rU57_4_50U1_1_D0N7_7rU57_N080DY}%
```

Flag: ```csd{1_D0N7_7rU57_4_50U1_1_D0N7_7rU57_N080DY}```

</details>

Write-up by [Vipin](https://vipinb.xyz)