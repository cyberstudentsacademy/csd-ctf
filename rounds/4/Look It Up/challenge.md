# Look It Up

- Published: 04/13/2024 (#7/14 in round)
- Category: WebEx/OSINT
- Points: 95
- Author: kshau

There was once a great page on the internet that contained this marvelous poem. That page has been long lost, but legend says that it still lies somewhere on this website in an HTML file known as "poem".

(Note: The "403 Forbidden" message is intentional)

## Attachments

- [https://csd.shaurya.pro/LookItUp](https://csd.shaurya.pro/LookItUp)

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

/LookItUp/poem.html is where the poem is stored. But if you already found it, then take a look at the discordguild cookie.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

- The HTML file poem refers to poem.html, which is accessed through [https://csd.shaurya.pro/LookItUp/poem.html](https://csd.shaurya.pro/LookItUp/poem.html)
- After going to the site, open up the dev browser tools and navigate to where the cookies are shown
- You should see a cookie named discordguild with a value of 1227723373673713786
- Input this numerical value into an online tool that gives you a Discord guild's name from a guild ID [https://discord-avatar.com/en/server](https://discord-avatar.com/en/server)
- The guild's name is the flag

Flag: csd{t6SVC6fI4Wv5sKzTPY}

</details>

Write-up by kshau
