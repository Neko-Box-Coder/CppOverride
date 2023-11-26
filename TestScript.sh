#!/bin/bash

#(
#    ls -lah
#) 2>&1 | tee output.txt

#my_variable="This is a multiline
#string with newlines."

PASSED_MESSAGE="## CI BOT
---

### ✅ X-Pipeline has passed
"

FAILED_MESSAGE="## CI BOT
---

### ❌ X-Pipeline has failed at X stage

\"Double quoted sentence\"

---

#### Failed Log

\`\`\`
Logs here
\`\`\`
"

FORMATTED_MESSAGE=$(echo "$FAILED_MESSAGE" | sed ':a
                                                N
                                                $!ba
                                                s/\n/\\n/g
                                                s/\"/\\\"/g'
                                                )

echo "$FORMATTED_MESSAGE"


