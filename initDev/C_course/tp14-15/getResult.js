const fs = require('fs');
const path = require('path');

let result = ``;

fs.readdirSync(path.join(__dirname)).map(program => {
    if( program.toString().endsWith('.c') ) {
        result += `\n\`\`\`c\n${fs.readFileSync(path.join(__dirname, program))}\n\`\`\`\n`;
    }
});

fs.writeFileSync(path.join(__dirname, 'result.md'), result);