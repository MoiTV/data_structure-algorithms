// The global variable
var globalTitle = 'Winter Is Coming';

// Only change code below this line
function urlSlug(title) {
    return title.toLowerCase();
}
// Only change code above this line
const newGlobalTitle = urlSlug(globalTitle);

console.log(newGlobalTitle);