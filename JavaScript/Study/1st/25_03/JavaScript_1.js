console.log( "프로그램 정상 실행" )

Reply( confirm("확인과 취소") );

function Reply( reply ) {
    if ( reply )
        PrintName( NameInput() );
    else
        alert("취소 ㅠ.ㅠ")
}

function PrintName( name ) {
    document.write( `<h1>${ name }님 환영합니다.</h1>` );
}

function NameInput() {
    return prompt( "이름을 입력해주세요.", "사용자" );
}