x = [-1, -8, -14, -19, -22, -26, -33, -38];
y = [23, 24, 27, 30, 30, 33, 33, 37];
plot(x, y);

A = [10, sum(x), sum(x.^2); sum(x), sum(x.^2), sum(x.^3); sum(x.^2), sum(x.^3), sum(x.^4)];
B = [sum(y); x*y'; x.^2 * y'];
C = A \ B;

y1 = C(1) + C(2) * x + C(3) * (x .^2);

hold on
plot(x, y1);
hold off
legend('Исходная функция', 'Аппроксимирующая функция');