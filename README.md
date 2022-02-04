# 디지털 영상 처리 using C

# **목차**

# 1. 프로젝트 개요

## 1-1. 프로젝트 개요 및 목표

### 1-1-1. 개요

- **C 언어를 기반으로 다양한 영상 처리 기능들을 구현하여 영상마다 필요한 기능을 적용하려 함.**

### 1-1-2. 프로젝트 목표

- **C 언어를 이용하여 화소 점 처리, 기하학 처리, 화소 영역 처리, 히스토그램 처리 구현.**
- **사용Tool : Visual Studio 2022 (Community)**

## 1-2. 프로젝트 진행 방법

- **영상 처리 프로그램 구조도 작성**

![Untitled](https://github.com/embeddedzlzon/GrayScaleProcessing/blob/master/Export-bf06f91d-d345-41d1-867e-5ef69a4394a2/%EB%94%94%EC%A7%80%ED%84%B8%20%EC%98%81%EC%83%81%20%EC%B2%98%EB%A6%AC%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%201.png)

# 2. 영상 처리 기능 구현 및 결과

[https://youtu.be/YaVBCynr5Sw](https://youtu.be/YaVBCynr5Sw)

## 2-1. 화소 점 처리

### 2-1-1. 밝기 처리

- **프로그램 실행**

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%201.png)

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%202.png)

```c
int px = inImage[i][k] + value;
if (px > 255) px = 255;
else if (px < 0) px = 0;
```

- 입력된 value 값에 따라 밝기 조절
- value 값이 너무 크거나 작을 때를 대비하기 위해 if문 사용

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%203.png)

```c
outImage[i][k] = inImage[i][k] / 1.5; // 나눗셈 처리
---------------------------------------------------
int px = inImage[i][k] * 1.5; // 곱셈 처리
if(px > 255) = px = 255; 
```

- 화소를 원하는 수로 나누어 사진을 희미하게 변화
- 화소를 원하는 수로 곱해 사진을 선명하게 변화
- 곱셈 시 화소가 최대 값을 넘는 것을 대비

### 2-1-2. 흑백 처리

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%204.png)

```c
sum += inImage[i][k];

avg = sum / (inH * inW); 

int px = inImage[i][k];

if (px >= avg) outImage[i][k] = 255;

else outImage[i][k] = 0;
```

- 기준을 화소 MAX 값의 반 or 화소 평균으로 설정
- 기준보다 높으면 255, 낮으면 0 처리

### 2-1-3. 반전

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%205.png)

```c
int px = 255 - inImage[i][k];
outImage[i][k] = px;
```

- 화소가 높은 값은 낮게

      화소가 낮은 값은 높게 변환

### 2-1-4. 감마 변환

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%206.png)

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%207.png)

- M : 화소 최대 값, x : 화소 값

       g : 감마 값

- 감마 변환 식에 의한 화소 값 변환

```c
outImage[i][k] = 255.0 * pow(((float)inImage[i][k] / 255.0), gamma);
```

### 2-1-5. 범위 강조

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%208.png)

```c
if (inImage[i][k] >= high_min && 

    inImage[i][k] <= hign_max)

    outImage[i][k] = 255;

else outImage[i][k] = inImage[i][k];
```

- 지정한 범위의 화소는 255로 강조

### 2-1-6. 파라볼라 변환

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%209.png)

$$
y = 255.0*(x / 127 - 1.0)^2 // cap변환
$$

$$
y = -255.0 * ( x/ 127 - 1.0)^2 +255.0 // cup 변환
$$

```c
outImage[i][k]  = 255.0 -255.0 * pow((float)inImage[i][k] / 127.0 - 1.0,2); // 캡 변환

------------------------------------------------------------------------------------------------------------

outImage[i][k] = 255.0 * pow((float)inImage[i][k] / 127.0 - 1.0, 2); // 컵 변환
```

- cap 변환 : 밝은 곳이 입체적으로 보임
- cup 변환 : 어두운 곳이 입체적으로 보임

### 2-1-7. 논리 연산

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2010.png)

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2011.png)

```c
outImage[i][k] = inImage[i][k] &  inGate[i][k] ; and 연산

outImage[i][k] = inImage[i][k] | inGate[i][k]; or 연산

outImage[i][k] = inImage[i][k] ^ inGate[i][k]; xor연산

outImage[i][k] = ~inImage[i][k]; not 연산
```

## 2-2. 기하학 적 변화

[https://youtu.be/3HAlem2WgK0](https://youtu.be/3HAlem2WgK0)

### 2-2-1. 축소

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2012.png)

```c
outH = inH / scale; outW = inW / scale;

for (int x = i * scale; x < i * scale + scale; x++) {
				for (int y = k * scale; y < k * scale + scale; y++) {
					if (x > inH - 1) x = inH - 1;
					if (y > inW - 1) y = inW - 1;
					sum += inImage[x][y];
				}
			}
			avg = sum / (pow(scale, 2));
			outImage[i][k] = avg;
```

- inImage의 가로, 세로를 scale로 나누어 outImage 가로, 세로 결정
- 주변 화소들과의 평균 값을 구해 축소 후에도 선이 끊기지 않음

### 2-2-2. 확대

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2013.png)

```c
outH = inH * scale;

outW = inW * scale;

outImage[i][k] = inImage[i / scale][k / scale]; // 백워딩
```

- inImage의 가로, 세로에 scale을 곱해 outImage의 가로, 세로 결정
- 포워딩 시 홀이 발생하므로 백워딩

### 2-2-3. 이미지 이동

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2014.png)

```c
if (i + y < outH – 1 && k + x < outW –1 && i + y >= 0 && k + x >= 0)

outImage[i + y][k + x] = inImage[i][k];
```

- x, y값을 입력 받은 후 x축, y축으로 이동

### 2-2-4. 미러링

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2015.png)

```c
outImage[i][(inW - 1) - k] = inImage[i][k]; // 좌우 미러링

outImage[(inH - 1) - i][k] = inImage[i][k]; // 상하 미러링

outImage[(inH - 1) - i][(inW - 1) - k] = inImage[i][k]; // 상하 + 좌우 미러링
```

### 2-2-5. 회전

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2016.png)

```c
outH = (int)(inH * abs(cos(radian)) + inW * abs(cos(3.141592 / 2 – radian);

outW = (int)(inH * abs(cos(3.141592 / 2 – radian)) + inW * abs(cos(radian));

int cx = outH / 2, cx = outH / 2 ,cx1 = inH / 2, cy2 = inW / 2

xs = cos(radian) * (xd – cx) + sin(radian) * (yd – cy) + cx1;

ys = -sin(radian) * (xd – cx) + cos(radian) * (yd –cy) + cy2;

if ((0 <= xs && xs < inH) && (0 <= ys && ys < inW))

                outImage2[xd][yd] = inImage[xs][ys];
```

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2017.png)

- 회전 시 outImage의 배열이 커져야 함.
- 공식에 의해 outH, outW 변환

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2018.png)

- 중심 점을 옮긴 후 회전
- xs값이 inImage 배열보다 클 수 없으므로 범위 통제

### 2-2-6 모핑

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2019.png)

```c
outImage[i][k] = (1 - rateMopImage) * inImage[i][k] + rateMopImage * inMop[i][k];
```

- 합칠 영상과 비율을 입력 받아 변환

## 2-3. 히스토그램 처리

[https://youtu.be/ib-cI45l6gE](https://youtu.be/ib-cI45l6gE)

### 2-3-1. 엔드 인

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2020.png)

```c
if (inImage[i][k] < low)low = inImage[i][k];

if (inImage[i][k] > high)high = inImage[i][k];

double res = (double)(inImage[i][k] - low) / (high - low) * 255.0;

outImage[i][k] = res;
```

- 가운데에 집중된 히스토그램을 모든 영역으로 확장
- 영상 화소의 최대 값, 최소 값을 구해 그 사이 영역을 모든 범위로 확대

### 2-3-2 평활화

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2021.png)

```c
histo[inImage[i][k]]++; // 히스토그램 생성

sumHisto[i] += sumHisto[i - 1] + histo[i]; // 누적 히스토그램 생성

normalHisto[i] = sumHisto[i] * (1.0 / (inH * inW)) * 255.0; // 정규화

outImage[i][k] = normalHisto[inImage[i][k]]; //  원래 값을 정규화 값으로
```

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2022.png)

- 명암 분포가 빈약한 영상을 균일하게 만듦
- 영상의 밝기 분포가 특히 뭉쳐 있는 곳을 재분배

## 2-4. 화소 영역 처리

### 2-4-1. 엠보싱

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2023.png)

```c
const int MSIZE = 3;

    double mask[MSIZE][MSIZE] = { // 마스크 배열

        {-1 , 0, 0},

        {0,  0,  0},

        {0,  0,  1} };

double** tmpIn, ** tmpOut; // inImage 처리 및 담을 공간

S += tmpIn[i + m][k + n] * mask[m][n]; // 마스크 배열과 화소들 곱의 합

tmpOut[i][k] = S;

double v = tmpOut[i][k];

outImage[i][k] = v; // 변환된 값을 outImage에 대입
```

- 마스크를 통해 한 화소의 주변 영역 처리
- 마스크 배열 값에 따라 다양한 효과 가능

### 2-4-2. 블러링, 엣지 검출, 샤프닝

![Untitled](%E1%84%83%E1%85%B5%E1%84%8C%E1%85%B5%E1%84%90%E1%85%A5%E1%86%AF%20%E1%84%8B%E1%85%A7%E1%86%BC%E1%84%89%E1%85%A1%E1%86%BC%20%E1%84%8E%E1%85%A5%E1%84%85%E1%85%B5%20using%20C%20b05da5eec4ca444aa542b4e55bffaeaa/Untitled%2024.png)

```c
const int MSIZE = 5;
	double mask[MSIZE][MSIZE] = { // 블러링 마스크
		{1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25},
		{1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25},
		{1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25}, 
		{1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25},
		{1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25} };

double mask[3][3] = { // 엣지 검출 마스크
        {1,  0,  -1},
        {1,  0,  -1},
        {1,  0,  -1}};

double mask[3][3] = { // 샤프닝 마스크
        {0,  -1,   0}
        {-1,  5,  -1},
        {0,  -1,   0} };
```

# 3. 향후 발전 방향

## 3-1. 느낀점

  C 언어 문법 중 포인터와 이차원 배열을 통해 영상을 받아와 화소 하나하나에 접근하여 영상의 개선을 이룰 수 있다는 것이 굉장히 신기했습니다. 흑백으로만 이루어진 영상에서도 많은 개선이 가능했기에 RGB가 접목된 영상에서는 더욱 다양한 변화가 기대됩니다.

## 3-2. 향후 발전 방향

- 프로그램 실행 시 메뉴에 불러오기 기능을 통해 이미지 출력하기
- 두 개의 영상을 입력 받아 출력할 때 서로 크기가 달라도 처리하기
- 영상 출력 시에 발생하는 딜레이 최소화하기
