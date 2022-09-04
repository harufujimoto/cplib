---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://old.yosupo.jp/problem/aplusb
    links:
    - https://old.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"aplusb.test.cpp\"\n#define PROBLEM \"https://old.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"template.cpp\"\n#include<iostream>\n\nusing namespace std;\nusing\
    \ ll = long long;\n\n\n#line 3 \"aplusb.test.cpp\"\n\nint main(void) {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(false);\n  ll a, b;\n  cin >> a >> b;\n  cout << a + b\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://old.yosupo.jp/problem/aplusb\"\n#include \"template.cpp\"\
    \n\nint main(void) {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  ll a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - template.cpp
  isVerificationFile: true
  path: aplusb.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 20:01:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: aplusb.test.cpp
layout: document
redirect_from:
- /verify/aplusb.test.cpp
- /verify/aplusb.test.cpp.html
title: aplusb.test.cpp
---
