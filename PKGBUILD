# Maintainer: foo <foo(at)example(dot)org>
# Contributor: bar <bar(at)example(dot)org>
_pkgbase=rcraid
pkgname=rcraid-dkms
pkgver=17.2.1
pkgrel=2
pkgdesc="AMD AM4 socket X370 chipset motherbroad NVMe/SATA RAID driver (DKMS)"
arch=('i686' 'x86_64')
url="https://www.amd.com/en/support/chipsets/amd-socket-am4/x370"
license=('GPL2')
depends=('dkms')
# conflicts=("${_pkgbase}")
# install=${pkgname}.install
source=('manual://raid_linux_driver_8_01_00_039_public.zip'
        'dkms.conf'
        'linux-4.15.patch'
        'linux-5.4.patch'
        'linux-5.6.patch'
        'linux-5.14.patch'
        'linux-5.16.patch'
        'linux-5.18.patch'
        'linux-6.2.patch'
        'linux-6.5.patch'
        'linux-6.6.patch'
        'linux-6.11.patch'
        'linux-6.14.patch'
        'linux-6.15.patch'
        'linux-6.16.patch'
        'linux-6.18.patch')
md5sums=('f5692d2ef952f8c903af90cdd9eb3ce6'
         '6f78c424353ae927e81bcbfec67afece'
         '461866e715a1fded49a3f7c043a173d7'
         'cac98de11cc5bd61fff72ff1c8cf363d'
         'bd1ef2b6bcefaec0abf7a832e937f01a'
         '916763c1eeb824f1c73e9dee717af05f'
         '848919b75f84a174a2d5d4025041aba0'
         '48561b77a9c3de2adb519305cfdb1248'
         '44d4591a3652ed8d6a5bb1ebed462312'
         '414bbbbe4884231ecb5107ba9bb3b891'
         '8b0efd9caa5b2a58006efc5c14759b29'
         '7709663aeeee89d2a8dc09a9ff16ba3f'
         '318eca1f828a62040469bb43dd731d94'
         'e09a474e5461f75cc99bdfe4ce1c0c96'
         '11cac54d40dc5b45b7a8b76544f68ce7'
         '849b9d9c89b27ea6c89ebaa14d8416a9')

prepare() {
    rm -rf ${_pkgbase}-${pkgver}
    cp -r driver_sdk/src ${_pkgbase}-${pkgver}
    cd ${_pkgbase}-${pkgver}

    # Patches are version-guarded, so all apply for any kernel
    local src
    for src in "${source[@]}"; do
        src="${src%%::*}"
        src="${src##*/}"
        src="${src%.zst}"
        [[ $src = *.patch ]] || continue
        echo "Applying patch $src..."
        patch -Np1 < "../$src"
    done
}

# No build(): DKMS compiles the module on install and for each new kernel
package() {
    local dest="${pkgdir}/usr/src/${_pkgbase}-${pkgver}"

    cd ${_pkgbase}-${pkgver}
    install -Dm644 -t "$dest" Makefile *.c *.h rcblob.*

    install -Dm644 "${srcdir}/dkms.conf" "$dest/dkms.conf"
    sed -e "s/@_PKGBASE@/${_pkgbase}/" \
        -e "s/@PKGVER@/${pkgver}/" \
        -i "$dest/dkms.conf"
}
