const aFriends = new Set(["박진우","박홍준","신채은"]);
const bFriends = new Set(["신채은","윤정후","윤태민"]);

console.log( [...aFriends].flatMap( x => bFriends.has( x ) ? [ x ] : [] )); // ["신채은"]