# Shared_Library

## <a id="목차" ></a>0. 목차
> 1. <a href="#개요" style="color: dimgray;">개요</a>
> 2. <a href="#export-리스트" style="color: dimgray;">Export 리스트</a>
> 3. <a href="#코드-작성-규칙" style="color: dimgray;">코드 작성 규칙</a>
> 4. <a href="#해더-가드-작성-규칙" style="color: dimgray;">해더 가드 작성 규칙</a>
> 5. <a href="#코드-정보" style="color: dimgray;">코드 정보</a>
> 6. <a href="#버전-정보" style="color: dimgray;">버전 정보</a>

## <a id="개요"></a>1. 개요 <a href="#목차" style="color: dimgray;">▲</a>
> - 명칭 : 공통 쉐어 정적 라이브러리
> - 용도 : 솔루션 프로젝트 전반의 공유 정적 라이브러리
> - 버전 : v1.0.0.0

## <a id="export-리스트"></a>2. Export 리스트 <a href="#목차" style="color: dimgray;">▲</a>
> -  정적 라이브러리

## <a id="코드-작성-규칙"></a>3. 코드 작성 규칙 <a href="#목차" style="color: dimgray;">▲</a>
### <a id="코드표기법" ></a> A. 표기법 <a href="#코드-작성-규칙" style="color: dimgray;">▲</a>
> - 기본 적으로 단어와 단어가 합성된 경우 <code>스네이크 표기법</code> 허용 
> - 네임 스페이스 <a href="#코드표기법" style="color: dimgray;">▲</a>
>    > - <code>카멜 표기법</code>
>    > - <code>명사형</code> 작성 권장
> - 클래스 <a href="#코드표기법" style="color: dimgray;">▲</a>
>    > - <code>파스칼 표기법</code>
>    > - <code>명사형</code> 작성 권장
> - 구조체(<code>struct</code>) <a href="#코드표기법" style="color: dimgray;">▲</a>
>    > - <code>파스칼 표기법</code>
>    > - 접두사 <code>_tag</code> 사용 가능
>    > - <code>table</code>과 같은 단어 선택으로 구조체라는 것을 명확하게 알 수 있도록 함
>    > - <code>명사형</code> 작성 권장
> - 이넘(<code>enum</code>) <a href="#코드표기법" style="color: dimgray;">▲</a>
>    > - 접두사 <code>E</code>를 붙인  <code>파스칼 표기법</code>
>    > - <code>명사형</code> 작성 권장
> - 함수 <a href="#코드표기법" style="color: dimgray;">▲</a>
>    > - <code>스네이크 표기법</code>
>    > - <code>동사형</code> 작성 권장
> - <a id="코드표기법-객체" ></a> 객체 <a href="#코드표기법" style="color: dimgray;">▲</a>
>    > - <code>카멜 표기법</code>
>    > - <code>명사형</code> 작성 권장
>    > - <code>is</code>, <code>check</code>, <code>cal</code> 등의 목적성을 띄는 단어 사용 권장 <a href="#코드표기법-객체" style="color: dimgray;">▲</a>
>    >    > - 해당 단어 사용시 앞에 선언될 수 있도록 함.
>    > - 맴버 변수 (class 변수) <a href="#코드표기법-객체" style="color: dimgray;">▲</a>
>    >    > - <code>private</code>의 경우  <code>_</code> 접두사 기입
>    > - 지역 변수 (함수 내부 생성 변수) <a href="#코드표기법-객체" style="color: dimgray;">▲</a>
>    >    > - 접두사 <code>temp</code> 사용 가능
>    > - 전역 변수 (static 또는 c 스타일 전역) <a href="#코드표기법-객체" style="color: dimgray;">▲</a>
>    >    > - 접두사 <code>g_</code> 사용 가능
>    > - 상수 <a href="#코드표기법-객체" style="color: dimgray;">▲</a>
>    >    > - <code>constexpr</code> 사용
>    >    > - 만약 전역으로 사용될 시에는 전역 함수로 사용하고 해더에 리니어 초기화를 할 것
>    >    > - 해당 사항이 불가능한 경우에는 <code>static</code> 문법 사용가능
>    > - 함수 객체 <a href="#코드표기법-객체" style="color: dimgray;">▲</a>
>    >    > - 변수와 같이 사용

### B. 작성 규칙 <a href="#코드-작성-규칙" style="color: dimgray;">▲</a>
> - 클래스의 경우에는 클래스 명과 파일 명이 같아야함
> - 폴더는 목적에 맞게 정리 필수
> - <code>pulbic</code> <code>static</code> 변수 사용 금지
>    > - 디자인 페턴과 같은 특수화 경우 제외
> - <code>enum</code> 대신 <code>enum class</code>를 사용, 부득이한 경우 사용
> - Get 함수 : <code>[[nodiscard]]</code>를 붙일 것
> - <code>Pointer</code>는 <code>std::</code><code>shared_ptr</code>, <code>std::</code><code>weak_ptr</code> 사용, <code>dll export</code>시에는 일반 포인터(<code>*</code>) 허용

## <a id="해더-가드-작성-규칙"></a>4. 해더 가드 작성 규칙 <a href="#목차" style="color: dimgray;">▲</a>
### A. 공통 사항 <a href="#해더-가드-작성-규칙" style="color: dimgray;">▲</a>
> - <code>0000000</code> 자신의 생성되는 로직의 이름
> - <code>0000000</code><code>.cpp</code>에 추가되는 자신 클래스 해더 (<code>0000000</code><code>.h</code>)는 해더가드를 하지않음
<br/>

### B. 접두사 <a href="#해더-가드-작성-규칙" style="color: dimgray;">▲</a>
> - 기능 생성 시 : <code>DECLARE_SHARED_LIBRARY_</code><code>0000000</code>
> - STD 사용 시 : <code>USE_STD_</code><code>0000000</code>
> - 내부 Code 사용 시 : <code>USE_SHARED_LIBRARY</code><code>0000000</code>
<br/>

### C. 접미사 <a href="#해더-가드-작성-규칙" style="color: dimgray;">▲</a>
> - 해더만 있는 경우 : <code>접두사</code><code>0000000</code>
> - 해더와 CPP가 같이있는경우
>    > - <code>.h</code> : <code>접두사</code><code>0000000</code><code>_H</code>
>    > - <code>.cpp</code> : <code>접두사</code><code>0000000</code><code>_CPP</code>
<br/>

## <a id="코드-정보">5. 코드 정보 <a href="#목차" style="color: dimgray;">▲</a>

## <a id="버전-정보">6. 버전 정보 <a href="#목차" style="color: dimgray;">▲</a>

<!-- v1.0.0.0 -->
<details close>
<summary style="font-size: 17.5px;">v1.0.0.0 <a href="#버전-정보" style="color: dimgray;">▲</a></summary>
<div>

> - 최초 생성
</div>
</details> 