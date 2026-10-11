let
  pkgs = import <nixpkgs> { };
in
pkgs.mkShell {
  packages = with pkgs; [
    gcc
    cmake
    pkg-config

    glfw
    wayland
    wayland-scanner
    libxkbcommon
    libffi
    libglvnd
  ];
  LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath (
    with pkgs;
    [
      wayland
      wayland-scanner
      libxkbcommon
      libffi
      libglvnd
    ]
  );
}
