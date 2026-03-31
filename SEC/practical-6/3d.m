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