# Name : Gaurang Tyagi
# Roll No. : 16

---

# 2-D Plotting

- Generate y1 = sin(x) and y2 = cos(x) for x = 0 : 0.01 : 2*pi
- Plot both using plot() with different colors ,markers and line styles
- Add title(), xlabel(), legend()
- Create a 2x2 subplot with with y1, y2, y1*y2, leaving one blank.
- Plot bar graph, pie chart, and histogram using bar(), pie(), histogram(), with

#### CODE

```matlab
clc;
clear;
close all;

% Generate values
x = 0:0.01:2*pi;
y1 = sin(x);
y2 = cos(x);

%% Plot sin and cos together
figure;
plot(x, y1, 'r--o', 'LineWidth',1);
hold on;
plot(x, y2, 'b:*', 'LineWidth',1);

title('Sine and Cosine Functions');
xlabel('x');
ylabel('Value');
legend('sin(x)','cos(x)');
grid on;

%% 2x2 Subplots
figure;

subplot(2,2,1)
plot(x,y1,'r')
title('sin(x)')
xlabel('x'); ylabel('sin(x)')

subplot(2,2,2)
plot(x,y2,'b')
title('cos(x)')
xlabel('x'); ylabel('cos(x)')

subplot(2,2,3)
plot(x,y1.*y2,'g')
title('sin(x) * cos(x)')
xlabel('x'); ylabel('Product')

% subplot(2,2,4) left blank intentionally

%% Bar Graph
figure;
data = [5 10 15 20 25];
bar(data,'FaceColor',[0.2 0.6 0.8])
title('Bar Graph Example')
xlabel('Category')
ylabel('Value')

%% Pie Chart
figure;
pie(data)
title('Pie Chart Example')

%% Histogram
figure;
randomData = randn(1000,1);
histogram(randomData)
title('Histogram Example')
xlabel('Values')
ylabel('Frequency')
```

#### OUTPUT
![sinx & cosx](./output.png)

![styles](./output-2.png)

![title](./output-3.png)

![subplot](./output-subplot.png)

custom colors and labels.
![histogram](./output-7.png)
![barplot](./output-5.png)
![pie](./output-6.png)

---

# 3-D plotting
- Create X,Y using meshgrid(-2:0.1:2) and compute Z = X.^2 - Y.^2.
- Plot 3D surface and mesh using surf(), mesh(), and contour().
- Apply colormap() and colorbar().
- Create a 3D line plot: x=cos(t), y=sin(t), z=t for t=0:0.1:10 using plot3(), customizing
- color and style.
- Add titles, labels, and legends.

#### CODE
```matlab
%% Meshgrid and Surface
[X,Y] = meshgrid(-2:0.1:2);
Z = X.^2 - Y.^2;

%% Surface Plot
figure;
surf(X,Y,Z)
title('3D Surface Plot')
xlabel('X')
ylabel('Y')
zlabel('Z')
colormap(jet)
colorbar

%% Mesh Plot
figure;
mesh(X,Y,Z)
title('Mesh Plot')
xlabel('X')
ylabel('Y')
zlabel('Z')

%% Contour Plot
figure;
contour(X,Y,Z)
title('Contour Plot')
xlabel('X')
ylabel('Y')
colorbar

%% 3D Line Plot
t = 0:0.1:10;
x = cos(t);
y = sin(t);
z = t;

figure;
plot3(x,y,z,'r','LineWidth',2)
grid on

title('3D Helix Line Plot')
xlabel('X')
ylabel('Y')
zlabel('Z')
legend('x=cos(t), y=sin(t), z=t')
```
#### OUTPUT

![3d surface](./output-8.png)
![mesh](./output-9.png)
![contour](./output-10.png)
![surf](./output-11.png)