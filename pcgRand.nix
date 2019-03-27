{ build-idris-package
, prelude
, base
, lib
, idris
}:

build-idris-package {
  name    = "pcgRand";
  version = "0.1";
  src = ./.;

  propagatedBuildInputs = [ prelude base ];

  meta = {
    description = "";
    license = "";
    maintainers = "";
  };

}


