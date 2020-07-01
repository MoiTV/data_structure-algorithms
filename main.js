function titleCase(str) {
    let words = str.toLowerCase().split(' ');

    let singleWord = words.map(
        upper => upper.charAt(0).toUpperCase() + upper.slice(1)
    );

    return singleWord.join(' ');
}

console.log(titleCase('sHoRt AnD sToUt'));