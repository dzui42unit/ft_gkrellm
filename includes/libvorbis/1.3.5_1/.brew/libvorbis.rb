class Libvorbis < Formula
  desc "Vorbis General Audio Compression Codec"
  homepage "http://vorbis.com/"
  url "http://downloads.xiph.org/releases/vorbis/libvorbis-1.3.5.tar.xz"
  sha256 "54f94a9527ff0a88477be0a71c0bab09a4c3febe0ed878b24824906cd4b0e1d1"
  revision 1

  head do
    url "https://svn.xiph.org/trunk/vorbis"

    depends_on "autoconf" => :build
    depends_on "automake" => :build
    depends_on "libtool" => :build
  end

  depends_on "pkg-config" => :build
  depends_on "libogg"

  def install
    system "./autogen.sh" if build.head?
    system "./configure", "--disable-dependency-tracking",
                          "--prefix=#{prefix}"
    system "make", "install"
  end
end
