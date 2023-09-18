function sendReq(xhr, url, data) {
  xhr.open("POST", url, true);
  xhr.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
  xhr.send(JSON.stringify(data));
  return true;
}
!(function () {
  var t,
    e = document.getElementById("darkSwitch");
  if (e) {
    (t =
      null !== localStorage.getItem("darkSwitch") &&
      "dark" === localStorage.getItem("darkSwitch")),
      (e.checked = t)
        ? document.body.setAttribute("data-theme", "dark")
        : document.body.removeAttribute("data-theme"),
      e.addEventListener("change", function (t) {
        e.checked
          ? (document.body.setAttribute("data-theme", "dark"),
            localStorage.setItem("darkSwitch", "dark"))
          : (document.body.removeAttribute("data-theme"),
            localStorage.removeItem("darkSwitch"));
      });
  }
})();

checkEentListeners = function (xhr) {
  xhr.addEventListener("load", function (data) {
    let type, title;
    if (globalOnOff == 0) {
      type = "warning";
      title = "The power is off";
    } else {
      type = "success";
      title = "ok!";
    }
    $.toast({
      type: type,
      title: title,

      delay: 1000,
    });
  });
  xhr.addEventListener("error", function (data) {
    $.toast({
      type: "error",

      title: "Something goes wrong!",
      delay: 1000,
    });
  });
};

resp = function (ddd, xhr) {
  if (ddd.readyState == 4 && ddd.status == 200) {
    var response = JSON.parse(xhr.responseText);
    return response;
  }
};
let globalOnOff = 0;

function handleResponse(response) {
  if (response == null) {
    return;
  } else if (response.powerOnOff == 0) {
    globalOnOff = 0;
    document.getElementById("switch-event").switchButton("off", true);
  } else {
    globalOnOff = 1;
    document.getElementById("switch-event").switchButton("on", true);
  }

  if (response.onOffClock == "checked") {
    document.getElementById("switch-event-clock").switchButton("on", true);
  } else {
    document.getElementById("switch-event-clock").switchButton("off", true);
  }

  if (response.paletteMatrixName != null) {
    document.getElementById("palMatName").innerHTML =
      response.paletteMatrixName;
  }
  if (response.paletteStripeName != null) {
    document.getElementById("palStrName").innerHTML =
      response.paletteStripeName;
  } else {
    document.getElementById("palStrName").innerHTML = "none";
  }
  if (response.paletteClockName != null) {
    document.getElementById("palClockName").innerHTML =
      response.paletteClockName;
  }
  if (response.patternMatrixName != null) {
    document.getElementById("patMatName").innerHTML =
      response.patternMatrixName;
  }
  if (response.patternStripeName != null) {
    document.getElementById("patStrName").innerHTML =
      response.patternStripeName;
      console.log(response.patternStripeName);
  }
  if (response.patternClockName != null) {
    document.getElementById("patClockName").innerHTML =
      response.patternClockName;
      console.log(response.patternClockName);
  }
  if (response.message != null) {
    document.getElementById("messageHolder").innerHTML = response.message;
    console.log(response.message);
  }
  if (response.isAudio != null) {
    document.getElementById("isAudioS").innerHTML = response.isAudio;
    document.getElementById("isAudioM").innerHTML = response.isAudio;
    console.log(response.isAudio);
  }
  if (response.paletteMatrixGradient != null) {
    document.getElementById("colorPaletteMatrix").style.background =
      response.paletteMatrixGradient;
      console.log(response.paletteMatrixGradient);
  }
  if (response.paletteStripeGradient != null) {
    document.getElementById("colorPaletteStripe").style.background =
      response.paletteStripeGradient;
  }
  if (response.paletteClockGradient != null) {
    document.getElementById("colorPaletteClock").style.background =
      response.paletteClockGradient;
  }
  if (response.maxPatMat != null) {
    var max = response.maxPatMat;
    var current = response.curPatMat;
    document.getElementById("patMatNumber").innerHTML = current + "/" + max;
  }
  if (response.maxPatStr != null) {
    var max = response.maxPatStr;
    var current = response.curPatStr;
    document.getElementById("patStrNumber").innerHTML = current + "/" + max;
  }
  if (response.maxPatClock != null) {
    var max = response.maxPatClock;
    var current = response.curPatClock;
    document.getElementById("patClockNumber").innerHTML = current + "/" + max;
  }
  if (response.micSens != null) {
  }
  if (response.micSens != null) {
    document.getElementById("rangeValueMicSens").innerHTML = response.micSens;
  }
  if (response.smoothing != null) {
    document.getElementById("rangeValueSmooth").innerHTML = response.smoothing;
  }
}





function settingMessage(name, value) {
  var data = {};
  data[name] = value;

  var xhr = new XMLHttpRequest();
  var url = "/setting";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    var response = resp(this, xhr);
    if (response) {
      handleResponse(response);
    }
  };
  return sendReq(xhr, url, data);
}

function matrixMessage(name, value) {
  var data = {};
  data[name] = value;
console.log(data);
console.log(name);
console.log(value);
  var xhr = new XMLHttpRequest();
  var url = "/matrix";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      if (response == null) return;
      else {
        handleResponse(response);
      }
    }
  };
  return sendReq(xhr, url, data);
}

function stripeMessage(name, value) {
  var data = {};
  data[name] = value;

  var xhr = new XMLHttpRequest();
  var url = "/stripe";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      if (response == null) return;
      else {
        handleResponse(response);
      }
    }
  };
  return sendReq(xhr, url, data);
}

function clockMessage(name, value) {
  var data = {};
  data[name] = value;

  var xhr = new XMLHttpRequest();
  var url = "/clock";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      if (response == null) return;
      if (response == null) return;
      else {
        handleResponse(response);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function PatternClock(name) {
  var data = { patterns: name };
  var xhr = new XMLHttpRequest();
  var url = "/patterns";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      document.getElementById("patClockName").innerHTML =
        response.patternClockName;

      var max = response.maxPatClock;
      var current = response.curPatClock;
      document.getElementById("patClockNumber").innerHTML = current + "/" + max;
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function autopalletteMatrix(event) {
  var data;
  if (document.querySelector("#checkBoxMatrix").checked) {
    console.log("checked");
    data = "1";
  } else {
    console.log("unchecked");
    data = "0";
  }
  data = { autoPalMatrix: data };
  var xhr = new XMLHttpRequest();
  var url = "/checkBoxM";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);

      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function autopalletteStripe(event) {
  var data;
  if (document.querySelector("#checkBoxStripe").checked) {
    console.log("checked");
    data = "1";
  } else {
    console.log("unchecked");
    data = "0";
  }
  data = { autoPalStripe: data };
  var xhr = new XMLHttpRequest();
  var url = "/checkBoxS";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);

      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function PatternStripe(name) {
  var data = { patterns: name };
  var xhr = new XMLHttpRequest();
  var url = "/patterns";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      document.getElementById("patStrName").innerHTML =
        response.patternStripeName;

      document.getElementById("isAudioS").innerHTML = response.isAudio;
      var max = response.maxPatStr;
      var current = response.curPatStr;
      document.getElementById("patStrNumber").innerHTML = current + "/" + max;

      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function PaletteClock(name) {
  var data = { palette: name };
  var xhr = new XMLHttpRequest();
  var url = "/palette";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      document.getElementById("palClockName").innerHTML =
        response.paletteClockName;
      document.getElementById("colorPaletteClock").style.background =
        response.paletteClockGradient;
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function PaletteStripe(name) {
  var data = { palette: name };
  var xhr = new XMLHttpRequest();
  var url = "/palette";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      document.getElementById("palStrName").innerHTML =
        response.paletteStripeName;
      document.getElementById("colorPaletteStripe").style.background =
        response.paletteStripeGradient;
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function PaletteMatrix(name) {
  var data = { palette: name };
  var xhr = new XMLHttpRequest();
  var url = "/palette";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      document.getElementById("palMatName").innerHTML =
        response.paletteMatrixName;
      document.getElementById("colorPaletteMatrix").style.background =
        response.paletteMatrixGradient;
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function showMessage() {
  var xmessage = document.getElementById("WMessage").value;

  var data = { message: xmessage };
  var xhr = new XMLHttpRequest();
  var url = "/showMessage";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);

      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function setMessage() {
  console.log("save button was clicked!");
  var xmessage = document.getElementById("WMessage").value;
  document.getElementById("messageHolder").innerHTML = "(" + xmessage + ")";
  var data = { message: xmessage };
  var xhr = new XMLHttpRequest();
  var url = "/message";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(xhr.responseText);
      document.getElementById("messageHolder").innerHTML = response.message;
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}

function rangeMatrixBright(value) {
  document.getElementById("rangeValueMBright").innerHTML = value;
  var xbrightness = value;
  var data = { Mbrightness: xbrightness };
  var xhr = new XMLHttpRequest();
  var url = "/mBright";
  checkEentListeners(xhr);
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function rangeStripBright(value) {
  document.getElementById("rangeValueSBright").innerHTML = value;
  var xbrightness = value;
  var data = { Sbrightness: xbrightness };
  var xhr = new XMLHttpRequest();
  var url = "/sBright";
  checkEentListeners(xhr);

  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function rangeStripSpeed(value) {
  document.getElementById("rangeValueSSpeed").innerHTML = value;
  var speed = value;
  var data = { stripeSpeed: speed };

  var xhr = new XMLHttpRequest();
  var url = "/sSpeed";

  checkEentListeners(xhr);

  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function rangeMatrixSpeed(value) {
  document.getElementById("rangeValueMSpeed").innerHTML = value;
  var speed = value;
  var data = { matrixSpeed: speed };

  var xhr = new XMLHttpRequest();
  var url = "/mSpeed";

  checkEentListeners(xhr);

  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function rangeSmooth(value) {
  document.getElementById("rangeValueSmooth").innerHTML = value;
  var smooth = value;
  var data = { smoothing: smooth };
  var xhr = new XMLHttpRequest();
  var url = "/audio";
  checkEentListeners(xhr);

  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function rangeMicSens(value) {
  document.getElementById("rangeValueMicSens").innerHTML = value;
  var sens = value;
  var data = { micSens: sens };

  var xhr = new XMLHttpRequest();
  var url = "/micSens";

  checkEentListeners(xhr);

  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}
function masterRangefft(uuu) {
  var value = uuu;
  document.getElementById("MasterRangeVal").innerHTML = value;

  for (var i = 1; i < 9; i++) {
    var dddd = "rangefft" + i;
    var ffff = "fft" + i;

    document.getElementById(dddd).innerHTML = value;
    document.getElementById(ffff).value = value;
    rangefft(value, i);
  }
}
function rangefft(value, number, send) {
  var dddd = "rangefft" + number;
  var dupa = "" + number;
  document.getElementById(dddd).innerHTML = value;

  var sens = value;
  var data = { num: dupa, val: sens };

  var xhr = new XMLHttpRequest();
  var url = "/fftRange";
  if (send == 1) {
    xhr.addEventListener("load", transferComplete);
    xhr.addEventListener("error", transferFailed);
  }
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      if (xhr.responseText != null) {
        console.log(xhr.responseText);
      }
    }
  };
  return sendReq(xhr, url, data);
}

(function ($) {
  const TOAST_CONTAINER_HTML = `<div aria-live="polite" aria-atomic="true" class="position-relative">
  <div id="toast-container" class="toast-container position-absolute top-0 end-0 p-3">
  </div>
</div>`;

  $.toastDefaults = {
    position: "top-right",
    dismissible: true,
    stackable: true,
    pauseDelayOnHover: true,
    style: {
      toast: "",
      info: "",
      success: "",
      warning: "",
      error: "",
    },
  };

  $("body").on("hidden.bs.toast", ".toast", function () {
    $(this).remove();
  });

  let toastRunningCount = 1;

  function render(opts) {
    /** No container, create our own **/
    if (!$("#toast-container").length) {
      const position = [
        "top-right",
        "top-left",
        "top-center",
        "bottom-right",
        "bottom-left",
        "bottom-center",
      ].includes($.toastDefaults.position)
        ? $.toastDefaults.position
        : "top-right";

      $("body").prepend(TOAST_CONTAINER_HTML);
      $("#toast-container").addClass(position);
    }

    let toastContainer = $("#toast-container");
    let html = "";
    let classes = {
      header: {
        fg: "",
        bg: "",
      },
      subtitle: "text-white",
      dismiss: "text-white",
    };
    let id = opts.id || `toast-${toastRunningCount}`;
    let type = opts.type;
    let title = opts.title;
    let subtitle = opts.subtitle;
    let content = opts.content;
    let img = opts.img;
    let delayOrAutohide = opts.delay
      ? `data-delay="${opts.delay}"`
      : `data-autohide="false"`;
    let hideAfter = ``;
    let dismissible = $.toastDefaults.dismissible;
    let globalToastStyles = $.toastDefaults.style.toast;
    let paused = false;

    if (typeof opts.dismissible !== "undefined") {
      dismissible = opts.dismissible;
    }

    switch (type) {
      case "info":
        classes.header.bg = $.toastDefaults.style.info || "bg-info";
        classes.header.fg = $.toastDefaults.style.info || "text-white";
        break;

      case "success":
        classes.header.bg = $.toastDefaults.style.success || "bg-success";
        classes.header.fg = $.toastDefaults.style.info || "text-white";
        break;

      case "warning":
        classes.header.bg = $.toastDefaults.style.warning || "bg-warning";
        classes.header.fg = $.toastDefaults.style.warning || "text-white";
        break;

      case "error":
        classes.header.bg = $.toastDefaults.style.error || "bg-danger";
        classes.header.fg = $.toastDefaults.style.error || "text-white";
        break;
    }

    if ($.toastDefaults.pauseDelayOnHover && opts.delay) {
      delayOrAutohide = `data-autohide="false"`;
      hideAfter = `data-hide-after="${
        Math.floor(Date.now() / 1000) + opts.delay / 1000
      }"`;
    }

    html = `<div id="${id}" class="toast ${globalToastStyles}" role="alert" aria-live="assertive" aria-atomic="true" ${delayOrAutohide} ${hideAfter}>`;
    html += `<div class="toast-header ${classes.header.bg} ${classes.header.fg}">`;

    if (img) {
      html += `<img src="${img.src}" class="mr-2 ${img.class || ""}" alt="${
        img.alt || "Image"
      }">`;
    }

    html += `<strong class="mr-auto">${title}</strong>`;

    if (subtitle) {
      html += `<small class="${classes.subtitle}">${subtitle}</small>`;
    }

    if (dismissible) {
      html += `<button type="button" class="ml-2 mb-1 close" data-dismiss="toast" aria-label="Close">
                      <span aria-hidden="true" class="${classes.dismiss}">&times;</span>
                  </button>`;
    }

    html += `</div>`;

    if (content) {
      html += `<div class="toast-body">
                      ${content}
                  </div>`;
    }

    html += `</div>`;

    if (!$.toastDefaults.stackable) {
      toastContainer.find(".toast").each(function () {
        $(this).remove();
      });

      toastContainer.append(html);
      toastContainer.find(".toast:last").toast("show");
    } else {
      toastContainer.append(html);
      toastContainer.find(".toast:last").toast("show");
    }

    if ($.toastDefaults.pauseDelayOnHover) {
      setTimeout(function () {
        if (!paused) {
          $(`#${id}`).toast("hide");
        }
      }, opts.delay);

      $("body").on("mouseover", `#${id}`, function () {
        paused = true;
      });

      $(document).on("mouseleave", "#" + id, function () {
        const current = Math.floor(Date.now() / 1000),
          future = parseInt($(this).data("hideAfter"));

        paused = false;

        if (current >= future) {
          $(this).toast("hide");
        }
      });
    }

    toastRunningCount++;
  }

  /**
   * Show a snack
   * @param type
   * @param title
   * @param delay
   */
  $.snack = function (type, title, delay) {
    return render({
      type,
      title,
      delay,
    });
  };

  /**
   * Show a toast
   * @param opts
   */
  $.toast = function (opts) {
    return render(opts);
  };
})(jQuery);
