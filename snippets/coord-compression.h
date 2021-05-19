vi arr(n+1), tempArr;
rep(i,n) {
    cin >> arr[i+1];
    tempArr.pb(arr[i+1]);
}

sort(all(tempArr));
tempArr.erase(unique(all(tempArr)), tempArr.end());

rep(i,n) {
    arr[i+1] = lower_bound(all(tempArr), arr[i+1]) - tempArr.begin() + 1;
}