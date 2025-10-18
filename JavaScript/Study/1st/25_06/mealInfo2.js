let currentDate = new Date();
function getCurrentDate() {
    const yyyy = currentDate.getFullYear();
    const mm = currentDate.getMonth() + 1;
    const dd = currentDate.getDate();
    return `${yyyy}${String(mm).padStart(2, '0')}${String(dd).padStart(2, '0')}`;
}

function changeDate( vdate ) {
    currentDate.setDate( currentDate.getDate() + vdate );
    getMealInfo();
}

async function getMealInfo() {
    const ATPT_OFCDC_SC_CODE = "B10";
    const SD_SCHUL_CODE = "7011569";
    const MLSV_YMD = getCurrentDate();
    console.log(MLSV_YMD);
    const dateDiv = document.getElementById("date");
    try {
        const response = await fetch ( `https://open.neis.go.kr/hub/mealServiceDietInfo?ATPT_OFCDC_SC_CODE=${ATPT_OFCDC_SC_CODE}&SD_SCHUL_CODE=${SD_SCHUL_CODE}&MLSV_YMD=${MLSV_YMD}&Type=json` )
        const data = await response.json();

        console.log(data);
        // console.log(data.mealServiceDietInfo[1].row[1].DDISH_NM);
        const mealinfoDiv = document.getElementById("mealInfo");
        mealinfoDiv.innerHTML = "";

        const dishDataArray = data.mealServiceDietInfo[1].row;
        dishDataArray.forEach(element => {
            const dishDiv = document.createElement("div");
            dishDiv.classList.add("col");
            console.log( "급식", element );
            // dishDiv.innerHTML = `<h2>${element.MMEAL_SC_NM}</h2>`;
            // dishDiv.innerHTML += `<h6>${element.MLSV_YMD}</h6>`;
            // dishDiv.innerHTML += element.DDISH_NM;
            dishDiv.innerHTML = `
            <div class="card h-100">
                <div class="card-body">
                    <h5 class="card-title">${element.MMEAL_SC_NM}</h5>
                    <p class="card-text">${element.DDISH_NM}</p>
                </div>
            </div>`;
            mealinfoDiv.appendChild(dishDiv);
        });
    } catch (error) {
        console.log(error)
    }

}