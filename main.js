function mutation(arr) {
    const test = arr[1].toLowerCase();
    const target = arr[0].toLowerCase();

    for (let i = 0; i < test.length; i++) {
        console.log(target.indexOf(test[i]));
        if (target.indexOf(test[i]) < 0) return false;
    }

    return true;
}

mutation(['Hello', 'hey']);