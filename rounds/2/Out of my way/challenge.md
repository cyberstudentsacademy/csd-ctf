# Out of my way

- Published: 02/07/2024 (#4/11 in round)
- Category: Web
- Points: 55
- Author: kshau & Vipin

are you http? because without you im ://

## Attachments

- https://8597638f-7de5-4e62-b2bb-e0c9c24a3c3a-00-1oogpfupm06r8.riker.replit.dev/

## Hint

This hint costed 15 points.

<details>
<summary>Reveal hint</summary>

robots.txt is a great place to check out

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

When visiting the website, we see that we have the first half of the flag: `csd{lptzubJCKtbrLn`. Websites have common
files such as `robots.txt` and `sitemap.xml`. The `robots.txt` file is a file that tells web crawlers (like Google)
restrictions when crawling the website. When visiting `/robots.txt`, we see this line:

```
Disallow: /bobots2
```

This tells us that there is a directory called `/bobots2` that should be hidden from web crawlers and search engines.
When visiting that directory, we don't see anything interesting at first. However, when we view the page source using
right-click > View Page Source or DevTools, we can see the second half of the flag hidden.

The flag is in reverse, so we can reverse it again to get the full flag.

Flag: `csd{lptzubJCKtbrLnRceminJErKwzrIAZo}`

</details>

Write-up by GodderE2D
