getMealInfo();
function getMealInfo() {
    const ATPT_OFCDC_SC_CODE = "B10";
    const SD_SCHUL_CODE = "7011569";
    const MLSV_YMD = "20250617";
    fetch( `https://open.neis.go.kr/hub/mealServiceDietInfo?ATPT_OFCDC_SC_CODE=${ ATPT_OFCDC_SC_CODE }&SD_SCHUL_CODE=${ SD_SCHUL_CODE }&MLSV_YMD=${ MLSV_YMD }&Type=json` )
        .then( response => response.json() )
        .then( data => {
            console.log( data );
            console.log( data.mealServiceDietInfo[1].row[1].DDISH_NM );
            const mealinfoDiv = document.getElementById( "mealInfo" );
            mealinfoDiv.innerHTML = "";
            
            const dishDataArray = data.mealServiceDietInfo[1].row;
            dishDataArray.forEach(element => {
                const dishDiv = document.createElement( "div" );
                dishDiv.classList.add( "dish" );
                dishDiv.innerHTML += element.DDISH_NM;
                mealinfoDiv.appendChild( dishDiv );
            });
        })
}