import 'dart:async';
import 'dart:math' show Random;

main() async {
  print('Compute ? using the Monte Carlo method.');
  await for (var estimate in computePi().take(500)) {
    print('? ? $estimate');
  }
}

/// Generates a stream of increasingly accurate estimates of ?.
Stream<double> computePi({int batch: 1000000}) async* {
  var total = 0;
  var count = 0;
  while (true) {
    var points = generateRandom().take(batch);
    var inside = points.where((p) => p.isInsideUnitCircle);
    total += batch;
    count += inside.length;
    var ratio = count / total;
    // Area of a circle is A = ??r�, therefore ? = A/r�.
    // So, when given random points with x ? <0,1>,
    // y ? <0,1>, the ratio of those inside a unit circle
    // should approach ? / 4. Therefore, the value of ?
    // should be:
    yield ratio * 4;
  }
}

Iterable<Point> generateRandom([int seed]) sync* {
  final random = new Random(seed);
  while (true) {
    yield new Point(random.nextDouble(), random.nextDouble());
  }
}

class Point {
  final double x, y;
  const Point(this.x, this.y);
  bool get isInsideUnitCircle => x * x + y * y <= 1;
}