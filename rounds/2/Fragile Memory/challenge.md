# Fragile Memory

- Published: 02/17/2024 (#10/11 in round)
- Category: Cryptography
- Points: 100
- Author: GodderE2D

One of our senior clients have forgotten their password, but he has composed a (rather large) list of the possible
passwords. Are you able to retrieve the password?

Tip: The flag is the password in `csd{password}` format. Remember, there is 30s cooldown between each attempt!

## Attachments

- https://fragile-memory-csctf.bsr.gg/
- https://replit.com/@GodderE2D/CSCTF-Fragile-Memory
- [password-list.txt](password-list.txt)

> [!IMPORTANT]  
> The website is no longer online, please visit the [Replit Repl](https://replit.com/@GodderE2D/CSCTF-Fragile-Memory)
> and fork it to try the challenge.

## Hint

This hint costed 20 points.

<details>
<summary>Reveal hint</summary>

Try to look around other pages of the site. Have you tried to utilise the browser DevTools to enable disabled features
and find hidden code? Perhaps you can filter down the passwords from the information you have learned.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

When visiting the homepage of the website, we are greeted with a login page. Since everything is non-functional on that
page, we can head to the `/sign-up.html` page that is linked.

The sign-up feature appears to be disabed, but after taking a look in the DevTools Elements tab, we can remove the
`disabled` attribute from the `<input>` elements. Now, we can try signing up, but an error message appears saying that
our password didn't meet the requirements.

That's fine, though. Taking a look at `/script.js` in the source code leads us to where the password is being checked:

<!-- prettier-ignore-start -->
```js
document.getElementById("sign-up").onclick = (e) => {
  const { value } = document.getElementById("password");
  const error = document.getElementById("error");

  if (value.length < 12)
    return (error.innerText = "Password must be at least 12 characters long.");
  if (!/\d{4,}/.test(value))
    return (error.innerText =
      "Password must include at least 4 consecutive numbers.");
  if (!value.includes("!"))
    return (error.innerText = "Password must include an exclamation mark.");
  if (!value.includes("?"))
    return (error.innerText = "Password must include a question mark.");
  if (!value.includes("*"))
    return (error.innerText = "Password must include an asterisk.");
  if (!value.includes("x"))
    return (error.innerText = "Password must be include an 'x'.");
  if (!value.includes("\u200b"))
    return (error.innerText = "Password must include a zero-width space.");
  if (value.includes("v"))
    return (error.innerText = "Password must not include a 'v'.");

  error.innerText = "";
  return alert("Your account has been sent to /dev/null.");
};
```
<!-- prettier-ignore-end -->

Given these requirements, we can write a script to filter down the passwords from the list we have
(`password-list.txt`). JavaScript was used here as it was also used for `script.js`.

```js
const { readFileSync } = require("fs");
const passwords = readFileSync("password-list.txt", "utf-8").split("\n");

for (const password of passwords) {
  if (password.length < 12) continue;
  if (!/\d{4,}/.test(password)) continue;
  if (!password.includes("!")) continue;
  if (!password.includes("?")) continue;
  if (!password.includes("*")) continue;
  if (!password.includes("x")) continue;
  if (!password.includes("\u200b")) continue;
  if (password.includes("v")) continue;

  console.log(password);
}
```

Running this script outputs the only password that meets all the criteria.

Flag: `csd{SFuf^Y?*p(ndCechwom5T​bl9WjZt#OiqxP!A&?M1y0483NI7JgRQEV}`

</details>

Write-up by GodderE2D
