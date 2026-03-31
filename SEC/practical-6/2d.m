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