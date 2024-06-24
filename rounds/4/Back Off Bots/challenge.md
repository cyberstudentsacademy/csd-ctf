# Back Off Bots

- Published: 04/15/2024 (#8/14 in round)
- Category: Web/Programming
- Points: 135
- Author: kshau

What can I say, this website just really doesn't like robots. 🤷‍♂️

## Attachments

- [https://csd.shaurya.pro/BackOffBots/](https://csd.shaurya.pro/BackOffBots/)

## Hint

This hint costed 30 points.

<details>
<summary>Reveal hint</summary>

Solve Map

Copy disallowed URLs > Convert into a wordlist > Use dirsearch to find working URL > Download Flag.txt > Figure out what file it is and find an online viewer > Flag!

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

- Visiting [https://csd.shaurya.pro/BackOffBots/robots.txt](https://csd.shaurya.pro/BackOffBots/robots.txt) shows us a list of disallowed URLs.
- Put them all into a list like this:

```txt
/index.html
/new_york_city.html
/los_angeles.html
/chicago.html
/houston.html
...
```
- Either use a tool like dirsearch or write your own script to find the working URL.

Example script:
```py
import requests

base_url = "https://csd.shaurya.pro/BackOffBots"

# name of the file containing the disallowed URLs = "paths.txt"
with open("paths.txt", "r") as file:
    paths = file.read().splitlines()

for path in paths:
    url = base_url + path
    response = requests.get(url)

    if response.status_code == 200:
        print(f"Found 200 response code for path: {path}")
```

- [https://csd.shaurya.pro/BackOffBots//vallejo.html](https://csd.shaurya.pro/BackOffBots//vallejo.html) is a working URL.
- Download the flag.txt file.
- The file has a comment telling us that it is a .obj file which you can view using an online viewer like [https://3dviewer.net/](https://3dviewer.net/)
- The flag is displayed in the 3D model.

Flag: `csd{v6z07E3CA}`

</details>

Write-up by kolmus
